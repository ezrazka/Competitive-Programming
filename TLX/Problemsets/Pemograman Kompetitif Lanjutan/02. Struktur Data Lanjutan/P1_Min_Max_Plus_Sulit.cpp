#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 2e9;

void chmax(int &a, int b){
    a = max(a, b);
}

void chmin(int &a, int b){
    a = min(a, b);
}

struct node {
    int max1, max2, cnt_max1;
    int min1, min2, cnt_min1;
    int sum;

    node() : max1(0), max2(-INF), cnt_max1(1), min1(0), min2(INF), cnt_min1(1), sum(0) {}
    node(int) : max1(-INF), max2(-INF), cnt_max1(0), min1(INF), min2(INF), cnt_min1(0), sum(0) {}
};

struct segment_tree {
    int n;
    vector<node> tree;
    vector<int> lazy;

    segment_tree(int n){
        this->n = n;
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(0, 0, n - 1);
    }

    node merge(const node &a, const node &b){
        node res;
        res.max1 = max(a.max1, b.max1);
        res.max2 = (a.max1 == b.max1 ? max(a.max2, b.max2) : max({min(a.max1, b.max1), a.max2, b.max2}));
        res.cnt_max1 = (a.max1 == b.max1 ? a.cnt_max1 + b.cnt_max1 : a.max1 > b.max1 ? a.cnt_max1 : b.cnt_max1);
        res.min1 = min(a.min1, b.min1);
        res.min2 = (a.min1 == b.min1 ? min(a.min2, b.min2) : min({max(a.min1, b.min1), a.min2, b.min2}));
        res.cnt_min1 = (a.min1 == b.min1 ? a.cnt_min1 + b.cnt_min1 : a.min1 < b.min1 ? a.cnt_min1 : b.cnt_min1);
        res.sum = a.sum + b.sum;
        return res;
    }

    void build(int pos, int low, int high){
        if (low == high){
            tree[pos] = node();
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid);
        build(2 * pos + 2, mid + 1, high);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void propagate(int pos, int low, int high){
        if (low != high){
            tree[2 * pos + 1].min1 = max(tree[2 * pos + 1].min1, tree[pos].min1);
            tree[2 * pos + 2].min1 = max(tree[2 * pos + 2].min1, tree[pos].min1);
            tree[2 * pos + 1].max1 = min(tree[2 * pos + 1].max1, tree[pos].max1);
            tree[2 * pos + 2].max1 = min(tree[2 * pos + 2].max1, tree[pos].max1);
        }
        if (lazy[pos] != 0){
            tree[pos].max1 += lazy[pos];
            if (tree[pos].max2 != -INF) tree[pos].max2 += lazy[pos];
            tree[pos].min1 += lazy[pos];
            if (tree[pos].min2 != INF) tree[pos].min2 += lazy[pos];
            tree[pos].sum += (high - low + 1) * lazy[pos];
            if (low != high){
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }

    void update_add(int pos, int low, int high, int q_low, int q_high, int val){
        propagate(pos, low, high);
        if (high < q_low || q_high < low){
            return;
        }
        if (q_low <= low && high <= q_high){
            lazy[pos] += val;
            propagate(pos, low, high);
            return;
        }

        int mid = (low + high) / 2;
        update_add(2 * pos + 1, low, mid, q_low, q_high, val);
        update_add(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void update_chmax(int pos, int low, int high, int q_low, int q_high, int val){
        propagate(pos, low, high);
        if (high < q_low || q_high < low || val <= tree[pos].min1){
            return;
        }
        if (q_low <= low && high <= q_high && tree[pos].min1 < val && val < tree[pos].min2){
            tree[pos].min1 = val;
            propagate(pos, low, high);
            return;
        }

        int mid = (low + high) / 2;
        update_chmax(2 * pos + 1, low, mid, q_low, q_high, val);
        update_chmax(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
    
    void update_chmin(int pos, int low, int high, int q_low, int q_high, int val){
        propagate(pos, low, high);
        if (high < q_low || q_high < low || val >= tree[pos].max1){
            return;
        }
        if (q_low <= low && high <= q_high && tree[pos].max2 < val && val < tree[pos].max1){
            tree[pos].max1 = val;
            propagate(pos, low, high);
            return;
        }

        int mid = (low + high) / 2;
        update_chmin(2 * pos + 1, low, mid, q_low, q_high, val);
        update_chmin(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    node query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (high < q_low || q_high < low){
            return node(0);
        }
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }

        int mid = (low + high) / 2;
        return merge(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n, q; cin >> n >> q;

    segment_tree tree(n);

    while (q--){
        for (int i = 0; i < n; i++){
            cout << tree.query(0, 0, n - 1, i, i).sum << " \n"[i == n - 1];
        }
        int qq; cin >> qq;
        if (qq == 1){
            int l, r, v; cin >> l >> r >> v; l--, r--;
            tree.update_add(0, 0, n - 1, l, r, v);
        } else if (qq == 2){
            int l, r, v; cin >> l >> r >> v; l--, r--;
            tree.update_chmax(0, 0, n - 1, l, r, v);
        } else {
            int l, r, v; cin >> l >> r >> v; l--, r--;
            tree.update_chmin(0, 0, n - 1, l, r, v);
        }
    }

    for (int i = 0; i < n; i++){
        cout << tree.query(0, 0, n - 1, i, i).sum << " \n"[i == n - 1];
    }
    /*
    previous solution stored lazy values for all of add, chmax, and chmin
    issue: the previous solution does not preserve the order of queries of different types

    treat tree[pos].max1 and tree[pos].min1 as representatives for lazy[pos].chmax and lazy[pos].chmin
        so instead of checking if there is an unprocessed lazy node,
        just propagate the max1/min1 of the node to its children
    
    since lazy[node] (now representing only add) updates max1/min1,
    its effectively like lazy[node].add affecting lazy[node].chmax and lazy[node].chmin
    we can update chmax/chmin before propagation and add after propagation, 2 cases:
    1. chmax/chmin happens before add: add updates chmax/chmin accordingly
    2. add happens before chmax/chmin: add is propagated first in update, then overwritten

    since min1 < min2 ≤ max2 < max1 we can always assume that chmin and chmax never affect
    each other, therefore their ordering doesnt matter
    except for the edge case where min1 == max1 (the segment it covers is all the same)

    therefore, ordering is preserved
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}