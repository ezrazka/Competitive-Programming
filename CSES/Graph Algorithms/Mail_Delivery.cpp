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
    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    bool is_eulerian_circuit = true;
    for (int i = 0; i < n; i++){
        if (adj[i].size() & 1){
            is_eulerian_circuit = false;
        }
    }

    if (!is_eulerian_circuit){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> vans;
    auto dfs = [&](auto self, int node) -> void {
        while (!adj[node].empty()){
            int child = *adj[node].begin();
            adj[node].erase(child);
            adj[child].erase(node);
            self(self, child);
        }
        vans.push_back(node);
    };
    dfs(dfs, 0);
    reverse(vans.begin(), vans.end());

    bool is_eulerian_path = (vans.size() == m + 1);
    if (!is_eulerian_path){
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