#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (c[u] != c[v]) ans += w;
    }
    
    vector<int> p(n);
    map<pair<int, int>, int> c_sum;
    map<pair<int, int>, int> edge_weights;
    auto dfs = [&](auto self, int node, int parent) -> void {
        p[node] = parent;
        for (auto [child, weight] : adj[node]){
            if (child != parent){
                c_sum[{node, c[child]}] += weight;
                edge_weights[{node, child}] = weight;
                self(self, child, node);
            }
        }
    };
    dfs(dfs, 0, -1);

    while (q--){
        int node, x; cin >> node >> x; node--;
        if (p[node] != -1){
            if (c[p[node]] != c[node]){
                ans -= edge_weights[{p[node], node}];
            }
            c_sum[{p[node], c[node]}] -= edge_weights[{p[node], node}];
        }
        ans += c_sum[{node, c[node]}];
        c[node] = x;
        ans -= c_sum[{node, c[node]}];
        if (p[node] != -1){
            if (c[p[node]] != c[node]){
                ans += edge_weights[{p[node], node}];
            }
            c_sum[{p[node], c[node]}] += edge_weights[{p[node], node}];
        }
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}