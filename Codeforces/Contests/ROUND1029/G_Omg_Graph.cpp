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
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist_start(n, 1e18);
    vector<int> dist_end(n, 1e18);
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist_start[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()){
            auto [dist, node] = pq.top(); pq.pop();
            if (dist > dist_start[node]) continue;
            for (auto [child, weight] : adj[node]){
                if (max(dist, weight) < dist_start[child]){
                    dist_start[child] = max(dist, weight);
                    pq.push({dist_start[child], child});
                }
            }
        }
    }
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist_end[n - 1] = 0;
        pq.push({0, n - 1});
        while (!pq.empty()){
            auto [dist, node] = pq.top(); pq.pop();
            if (dist > dist_end[node]) continue;
            for (auto [child, weight] : adj[node]){
                if (max(dist, weight) < dist_end[child]){
                    dist_end[child] = max(dist, weight);
                    pq.push({dist_end[child], child});
                }
            }
        }
    }

    int ans = 1e18;
    for (int node = 0; node < n; node++){
        for (auto [child, weight] : adj[node]){
            ans = min(ans, max({weight, dist_start[node], dist_end[child]}) + weight);
        }
    }
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