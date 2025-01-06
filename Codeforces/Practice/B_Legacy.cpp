#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

#warning must be power of 2?

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;
    vector<T> lazy;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, {1e18, n});
        lazy.assign(4 * n, {1e18, n});
        vector<pair<int, int>> base(n);
        for (int i = 0; i < n; i++){
            base[i] = {1e18, i};
        }
        build(0, 0, n - 1, base);
    }

    T merge(T a, T b, bool lazy = false){
        if (lazy){
            if (a.se == -1 && b.se == -1) return {1e18, -1};
            if (a.se == -1) return {b.fi, a.se};
            if (b.se == -1) return a;
            return min(a, {b.fi, a.se});
        }
        if (a.se == -1 && b.se == -1) return {1e18, -1};
        if (a.se == -1) return b;
        if (b.se == -1) return a;
        return min(a, b);
    }

    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void propagate(int pos, int low, int high){
        if (lazy[pos].fi != 1e18){
            tree[pos] = merge(tree[pos], lazy[pos], true);
            if (low != high){
                lazy[2 * pos + 1] = merge(lazy[2 * pos + 1], lazy[pos]);
                lazy[2 * pos + 2] = merge(lazy[2 * pos + 2], lazy[pos]);
            }
            lazy[pos] = {1e18, n};
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, int val){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            lazy[pos] = merge(lazy[pos], {val, lazy[pos].se});
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

    void remove(int pos, int low, int high, int idx){
        propagate(pos, low, high);
        if (low == high){
            tree[pos].se = -1;
            propagate(pos, low, high);
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid){
            remove(2 * pos + 1, low, mid, idx);
        } else {
            remove(2 * pos + 2, mid + 1, high, idx);
        }
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return {1e18, -1};
        }

        int mid = (low + high) / 2;
        return merge(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n, q, s; cin >> n >> q >> s; s--;

    vector<vector<pair<pair<int, int>, int>>> adj_from(n), adj_to(n);
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int u, v, w; cin >> u >> v >> w; u--, v--;
            adj_from[u].push_back({{v, v}, w});
        } else if (qq == 2){
            int u, l, r, w; cin >> u >> l >> r >> w; u--, l--, r--;
            adj_from[u].push_back({{l, r}, w});
        } else {
            int u, l, r, w; cin >> u >> l >> r >> w; u--, l--, r--;
            adj_to[u].push_back({{l, r}, w});
        }
    }

    segment_tree<pair<int, int>> tree(n), vis(n);
    tree.update(0, 0, n - 1, s, s, 0);
    vis.update(0, 0, n - 1, s, s, 0);
    int node = vis.query(0, 0, n - 1, 0, n - 1).se;
    while (node != -1){
        for (auto [range, weight] : adj_to[node]){
            int res = tree.query(0, 0, n - 1, range.fi, range.se).fi;
            tree.update(0, 0, n - 1, node, node, res + weight);
            vis.update(0, 0, n - 1, node, node, res + weight);
        }
        for (auto [range, weight] : adj_from[node]){
            int res = tree.query(0, 0, n - 1, node, node).fi;
            tree.update(0, 0, n - 1, range.fi, range.se, res + weight);
            vis.update(0, 0, n - 1, range.fi, range.se, res + weight);
        }
        vis.remove(0, 0, n - 1, node);
        node = vis.query(0, 0, n - 1, 0, n - 1).se;
    }

    for (int i = 0; i < n; i++){
        int ans = tree.query(0, 0, n - 1, i, i).fi;
        cout << (ans == 1e18 ? -1 : ans) << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}