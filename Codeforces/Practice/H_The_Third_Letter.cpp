#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, -w});
    }

    vector<int> coords(n, 1e18);
    vector<bool> vis(n);
    bool ok = true;
    auto dfs = [&](auto self, int node) -> void {
        vis[node] = true;
        for (auto [child, weight] : adj[node]){
            if (coords[child] != 1e18 && coords[child] != coords[node] - weight){
                ok = false;
            }
            coords[child] = coords[node] - weight;
            if (!vis[child]) self(self, child);
        }
    };

    for (int node = 0; node < n; node++){
        if (!vis[node]){
            coords[node] = 0;
            dfs(dfs, node);
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}