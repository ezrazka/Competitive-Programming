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
    vector<vector<int>> capacity(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += w;
    }

    vector<int> dist(n, -1);
    auto bfs = [&]() -> bool {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()){
            int node = q.front(); q.pop();
            for (int child : adj[node]){
                if (dist[child] == -1 && capacity[node][child] > 0){
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
        return dist[n - 1] != -1;
    };

    vector<int> next(n);
    auto dfs = [&](auto self, int node, int flow) -> int {
        if (node == n - 1) return flow;
        while (next[node] < adj[node].size()){
            int child = adj[node][next[node]];
            if (dist[node] + 1 == dist[child] && capacity[node][child] > 0){
                if (int pushed = self(self, child, min(flow, capacity[node][child]))){
                    capacity[node][child] -= pushed;
                    capacity[child][node] += pushed;
                    return pushed;
                }
            }
            next[node]++;
        }
        return 0;
    };

    int ans = 0;
    while (bfs()){
        fill(next.begin(), next.end(), 0);
        while (int flow = dfs(dfs, 0, 1e18)){
            ans += flow;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}