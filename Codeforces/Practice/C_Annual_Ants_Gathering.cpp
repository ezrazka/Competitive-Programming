#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> neighbors(n);
    for (int node = 0; node < n; node++){
        neighbors[node] = adj[node].size();
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> sz(n, 1);
    for (int node = 0; node < n; node++){
        if (neighbors[node] == 1){
            pq.push({sz[node], node});
        }
    }

    vector<bool> vis(n);
    bool ok = true;
    while (!pq.empty()){
        auto [_, node] = pq.top(); pq.pop();
        vis[node] = true;
        for (int child : adj[node]){
            if (vis[child]) continue;
            if (sz[node] > sz[child]){
                ok = false;
            }
            sz[child] += sz[node];
            if (--neighbors[child] == 1){
                pq.push({sz[child], child});
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}