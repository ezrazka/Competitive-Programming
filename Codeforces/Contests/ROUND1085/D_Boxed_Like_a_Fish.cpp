#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k, v; cin >> n >> k >> v; v--;
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = false;
    vector<int> depth(n, n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        if (adj[node].size() == 1){
            depth[node] = 0;
            return;
        }
        int mn1 = n, mn2 = n;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                depth[node] = min(depth[node], depth[child] + 1);
                if (mn1 > depth[child]) mn2 = mn1, mn1 = depth[child];
                else if (mn2 > depth[child]) mn2 = depth[child];
            }
        }
        if (mn1 + mn2 < k) depth[node] = 0;
    };
    dfs(dfs, v, -1);

    cout << (depth[v] == 0 ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}