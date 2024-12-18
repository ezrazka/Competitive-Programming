#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, m; cin >> a >> b >> m;
    int n = a + b + 2;
    int source = n - 2, sink = n - 1;
    vector<vector<int>> adj(n);
    vector<vector<int>> capacity(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        if (capacity[u][a + v] == 0){
            adj[u].push_back(a + v);
            adj[a + v].push_back(u);
            capacity[u][a + v]++;
        }
    }

    for (int i = 0; i < a; i++){
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i]++;
    }
    for (int i = a; i < a + b; i++){
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        capacity[i][sink]++;
    }

    vector<int> dist(n, -1);
    auto bfs = [&]() -> bool {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;
        dist[source] = 0;
        q.push(source);
        while (!q.empty()){
            int node = q.front(); q.pop();
            for (int child : adj[node]){
                if (dist[child] == -1 && capacity[node][child] > 0){
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
        return dist[sink] != -1;
    };

    vector<int> next(n);
    auto dfs = [&](auto self, int node, int flow) -> int {
        if (node == sink) return flow;
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

    while (bfs()){
        fill(next.begin(), next.end(), 0);
        while (dfs(dfs, source, 1e18));
    }

    vector<pii> vans;
    for (int boy = 0; boy < a; boy++){
        for (int girl : adj[boy]){
            if (a <= girl && girl < a + b && capacity[boy][girl] == 0){
                vans.push_back({boy, girl - a});
            }
        }
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i].fi + 1 << ' ' << vans[i].se + 1 << '\n';
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