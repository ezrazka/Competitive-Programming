#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct segment_tree {
    int n;
    vector<pair<int, int>> tree;
    vector<int> lazy;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, {0, 1});
        lazy.assign(4 * n, 0);
    }

    pair<int, int> merge(pair<int, int> a, pair<int, int> b){
        if (a.fi < b.fi) return a;
        if (a.fi > b.fi) return b;
        return {a.fi, a.se + b.se};
    }

    void init(int pos, int low, int high){
        if (low == high){
            return;
        }

        int mid = (low + high) / 2;
        init(2 * pos + 1, low, mid);
        init(2 * pos + 2, mid + 1, high);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void propagate(int pos, int low, int high){
        if (lazy[pos] != 0){
            tree[pos].fi += lazy[pos];
            if (low != high){
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, int val){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            lazy[pos] += val;
            propagate(pos, low, high);
            return;
        }
        if (high < q_low || q_high < low){
            return;
        }

        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, q_low, q_high, val);
        update(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    pair<int, int> query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return {1e9, -1};
        }

        int mid = (low + high) / 2;
        return merge(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n; cin >> n;
    int mx = 2e6 + 1;
    vector<vector<pair<int, int>>> adds(mx), removes(mx + 1);
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6, y1 += 1e6, x2 += 1e6, y2 += 1e6;
        adds[x1].push_back({y1, y2});
        removes[x2].push_back({y1, y2});
    }

    segment_tree tree(mx);
    tree.init(0, 0, mx - 1);

    int ans = 0;
    for (int i = 0; i < mx; i++){
        for (auto [l, r] : adds[i]){
            tree.update(0, 0, mx - 1, l, r - 1, 1);
        }
        for (auto [l, r] : removes[i]){
            tree.update(0, 0, mx - 1, l, r - 1, -1);
        }
        pair<int, int> q = tree.query(0, 0, mx - 1, 0, mx - 1);
        ans += mx - (q.fi == 0 ? q.se : 0);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}