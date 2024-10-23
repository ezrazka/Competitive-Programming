#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

#define int long long

struct node {
    int leftmost;
    int rightmost;
    int leftmost2;
    int rightmost2;

    node(){
        leftmost = -1;
        rightmost = -1;
        leftmost2 = 0;
        rightmost2 = 0;
    }
};

struct segment_tree {
    int n;
    vector<node> tree;
    vector<node> lazy;
 
    segment_tree(int n){
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    node merge(node a, node b){
        node res;
        res.leftmost = a.leftmost;
        res.rightmost = b.rightmost;
        res.leftmost2 = min(a.leftmost2, b.leftmost2);
        res.rightmost2 = min(a.rightmost2, b.rightmost2);
        return res;
    }
 
    void build(int pos, int low, int high, const vector<int>& p, const vector<int>& l, const vector<int>& r){
        if (low == high){
            tree[pos].leftmost = l[low];
            tree[pos].rightmost = r[low];
            tree[pos].leftmost2 = p[low] - l[low];
            tree[pos].rightmost2 = r[low] - p[low];
            // cout << tree[pos].leftmost << ' ' << tree[pos].rightmost << ' ' << tree[pos].leftmost2 << ' ' << tree[pos].rightmost2 << '\n';
            return;
        }
 
        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, p, l, r);
        build(2 * pos + 2, mid + 1, high, p, l, r);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
 
    void propagate(int pos, int low, int high){
        if (lazy[pos].leftmost != -1){
            tree[pos].leftmost = lazy[pos].leftmost;
            if (low != high){
                lazy[2 * pos + 1].leftmost = lazy[pos].leftmost;
                lazy[2 * pos + 2].leftmost = lazy[pos].leftmost;
            }
        }
        if (lazy[pos].rightmost != -1){
            tree[pos].rightmost = lazy[pos].rightmost;
            if (low != high){
                lazy[2 * pos + 1].rightmost = lazy[pos].rightmost;
                lazy[2 * pos + 2].rightmost = lazy[pos].rightmost;
            }
        }
        if (lazy[pos].leftmost2 != 0){
            tree[pos].leftmost2 += lazy[pos].leftmost2;
            if (low != high){
                lazy[2 * pos + 1].leftmost2 += lazy[pos].leftmost2;
                lazy[2 * pos + 2].leftmost2 += lazy[pos].leftmost2;
            }
        }
        if (lazy[pos].rightmost2 != 0){
            tree[pos].rightmost2 += lazy[pos].rightmost2;
            if (low != high){
                lazy[2 * pos + 1].rightmost2 += lazy[pos].rightmost2;
                lazy[2 * pos + 2].rightmost2 += lazy[pos].rightmost2;
            }
        }
        lazy[pos] = node();
    }
 
    void update(int pos, int low, int high, int q_low, int q_high, int a, int b, int c, int d){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            lazy[pos].leftmost = a;
            lazy[pos].rightmost = b;
            lazy[pos].leftmost2 += c;
            lazy[pos].rightmost2 += d;
            propagate(pos, low, high);
            return;
        }
        if (high < q_low || q_high < low){
            return;
        }
 
        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, q_low, q_high, a, b, c, d);
        update(2 * pos + 2, mid + 1, high, q_low, q_high, a, b, c, d);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
 
    node query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return node();
        }
 
        int mid = (low + high) / 2;
        return merge(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n, q; cin >> n >> q;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i], p[i]--;
        }
        string s; cin >> s;

        vector<pii> intervals;
        pii cur = {0, 0};
        for (int i = 0; i < n - 1; i++){
            if (s[i] == 'L' && s[i + 1] == 'R'){
                intervals.push_back(cur);
                cur = {i + 1, i + 1};
            } else {
                cur.se++;
            }
        }
        intervals.push_back(cur);

        int j = 0;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++){
            if (i > intervals[j].se) j++;
            left[i] = intervals[j].fi;
            right[i] = intervals[j].se;
        }

        n = (1 << ((int) log2(n - 1) + 1));
        segment_tree tree(n);
        tree.build(0, 0, n - 1, p, left, right);

        // node ans = tree.query(0, 0, n - 1, 0, n - 1);
        // cout << ans.leftmost2 << ' ' << ans.rightmost2 << '\n';
        // int leftmost = tree.query(0, 0, n - 1, 3, 3).leftmost;
        // int rightmost = tree.query(0, 0, n - 1, 3 + 1, 3 + 1).rightmost;
        // cout << -3 << ' ' << rightmost << ' ' << 3 + 1 << ' ' << leftmost << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << left[i] << ' ' << right[i] << '\n';
        // }

        while (q--){
            int idx; cin >> idx; idx--;
            if (s[idx] == 'L'){
                s[idx] = 'R';
                if (idx - 1 >= 0 && s[idx - 1] == 'L'){
                    int leftmost = tree.query(0, 0, n - 1, idx - 1, idx - 1).leftmost;
                    int rightmost = tree.query(0, 0, n - 1, idx, idx).rightmost;
                    tree.update(0, 0, n - 1, leftmost, idx - 1, -1, idx - 1, 0, -rightmost + (idx - 1));
                    tree.update(0, 0, n - 1, idx, rightmost, idx, -1, leftmost - (idx), 0);
                }
                if (idx + 1 < n && s[idx + 1] == 'R'){
                    int leftmost = tree.query(0, 0, n - 1, idx, idx).leftmost;
                    int rightmost = tree.query(0, 0, n - 1, idx + 1, idx + 1).rightmost;
                    cout << -idx << ' ' << rightmost << ' ' << idx + 1 << ' ' << leftmost << '\n';
                    cout << -(idx) + rightmost << ' ' << (idx + 1) - leftmost << '\n';
                    tree.update(0, 0, n - 1, leftmost, idx, -1, rightmost, 0, -(idx) + rightmost);
                    tree.update(0, 0, n - 1, idx + 1, rightmost, leftmost, -1, (idx + 1) - leftmost, 0);
                }
            } else {
                s[idx] = 'L';
                if (idx + 1 < n && s[idx + 1] == 'R'){
                    int leftmost = tree.query(0, 0, n - 1, idx, idx).leftmost;
                    int rightmost = tree.query(0, 0, n - 1, idx + 1, idx + 1).rightmost;
                    tree.update(0, 0, n - 1, leftmost, idx, -1, idx, 0, -rightmost + (idx));
                    tree.update(0, 0, n - 1, idx + 1, rightmost, idx + 1, -1, leftmost - (idx + 1), 0);
                }
                if (idx - 1 >= 0 && s[idx - 1] == 'L'){
                    int leftmost = tree.query(0, 0, n - 1, idx - 1, idx - 1).leftmost;
                    int rightmost = tree.query(0, 0, n - 1, idx, idx).rightmost;
                    tree.update(0, 0, n - 1, leftmost, idx - 1, -1, rightmost, 0, -(idx - 1) + rightmost);
                    tree.update(0, 0, n - 1, idx, rightmost, leftmost, -1, (idx) - leftmost, 0);
                }
            }

            node ans = tree.query(0, 0, n - 1, 0, n - 1);
            cout << ans.leftmost2 << ' ' << ans.rightmost2 << '\n';
            cout << (ans.leftmost2 >= 0 && ans.rightmost2 >= 0 ? "YES\n" : "NO\n");
        }
        cout << endl;
        // leftmost, rightmost, rightmost minus value, value minus leftmost
    }
}