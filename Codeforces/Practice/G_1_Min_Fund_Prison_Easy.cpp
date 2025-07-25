#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, c; cin >> n >> m >> c;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1e18;
    vector<int> sz(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        sz[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                sz[node] += sz[child];
            }
        }
        if (parent != -1){
            ans = min(ans, sz[node] * sz[node] + (n - sz[node]) * (n - sz[node]));
        }
    };
    dfs(dfs, 0, -1);

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}