#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n);
    auto dfs = [&](auto self, int node){
        if (vis[node]) return;
        vis[node] = true;
        for (int child : adj[node]){
            self(self, child);
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(dfs, i);
            ans++;
        }
    }
    cout << ans << '\n';
}