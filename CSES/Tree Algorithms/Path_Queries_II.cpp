#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n){
        n = (1 << (32 - __builtin_clz(n - 1)));
        this->n = n;
        tree.assign(2 * n, 0);
    }

    void update(int idx, T val){
        tree[idx + n] = val;
        for (int i = (idx + n) / 2; i >= 1; i /= 2){
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(int low, int high){
        T res = 0;
        int l = low + n, r = high + n;
        while (l <= r){
            if (l % 2 == 1) res = max(res, tree[l]), l++;
            if (r % 2 == 0) res = max(res, tree[r]), r--;
            l /= 2, r /= 2;
        }
        return res;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    segment_tree<int> tree(n);

    vector<int> sz(n), depth(n), p(n);
    p[0] = -1;
    auto dfs = [&](auto self, int node, int parent) -> void {
        sz[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                depth[child] = depth[node] + 1;
                p[child] = node;
                self(self, child, node);
                sz[node] += sz[child];
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<int> id(n), top(n);
    int timer = 0;
    auto dfs_hld = [&](auto self, int node, int parent, int cur_top) -> void {
        id[node] = timer++;
        top[node] = cur_top;
        tree.update(id[node], v[node]);
        int heavy_child = -1;
        for (int child : adj[node]){
            if (child != parent){
                if (heavy_child == -1 || sz[child] > sz[heavy_child]){
                    heavy_child = child;
                }
            }
        }
        if (heavy_child != -1){
            self(self, heavy_child, node, cur_top);
            for (int child : adj[node]){
                if (child != parent && child != heavy_child){
                    self(self, child, node, child);
                }
            }
        }
    };
    dfs_hld(dfs_hld, 0, -1, 0);

    auto query = [&](int a, int b) -> int {
        int res = 0;
        while (top[a] != top[b]){
            if (depth[top[a]] < depth[top[b]]) swap(a, b);
            res = max(res, tree.query(id[top[a]], id[a]));
            a = p[top[a]];
        }
        if (depth[a] > depth[b]) swap(a, b);
        res = max(res, tree.query(id[a], id[b]));
        return res;
    };
    // proof for time complexity: log n light edges in a path from root to leaf, therefore log n heavy edges
    // proof for LCA correctness

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx, val; cin >> idx >> val; idx--;
            v[idx] = val;
            tree.update(id[idx], val);
        } else {
            int a, b; cin >> a >> b; a--, b--;
            cout << query(a, b) << ' ';
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}