#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n), outdegree(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        indegree[v]++;
        outdegree[u]++;
    }

    bool ok = (indegree[0] + 1 == outdegree[0] && indegree[n - 1] == outdegree[n - 1] + 1);
    for (int i = 1; i < n - 1; i++){
        if (indegree[i] != outdegree[i]){
            ok = false;
        }
    }

    if (!ok){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> vans;
    auto dfs = [&](auto self, int node) -> void {
        while (!adj[node].empty()){
            int child = adj[node].back();
            adj[node].pop_back();
            self(self, child);
        }
        vans.push_back(node);
    };
    dfs(dfs, 0);
    reverse(vans.begin(), vans.end());

    if (vans.size() < m + 1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < m + 1; i++){
        cout << vans[i] + 1 << " \n"[i == m];
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