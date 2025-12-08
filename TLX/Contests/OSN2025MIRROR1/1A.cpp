#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

signed main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<pair<int, int>>> adj_z2(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        int w, z; cin >> w >> z;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (z == 2){
            adj_z2[u].push_back({v, w});
            adj_z2[v].push_back({u, w});
        }
    }

    int q; cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++){
        int t; cin >> t;
        queries[i] = {t, i};
    }
    sort(queries.begin(), queries.end());

    vector<int> dist_z2(n, INF);
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist_z2[n - 1] = 0;
        pq.push({dist_z2[n - 1], n - 1});
        while (!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist_z2[node]) continue;
            for (auto [child, weight] : adj_z2[node]){
                if (dist_z2[node] + weight < dist_z2[child]){
                    dist_z2[child] = dist_z2[node] + weight;
                    pq.push({dist_z2[child], child});
                }
            }
        }
    }

    vector<int> vans(q, INF);
    vector<int> dist(n, INF);
    {
        int query = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({dist[0], 0});
        while (!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            while (query < q && queries[query].first < d) query++;
            if (query < q) vans[queries[query].second] = min(vans[queries[query].second], d + dist_z2[node]);
            for (auto [child, weight] : adj[node]){
                if (dist[node] + weight < dist[child]){
                    dist[child] = dist[node] + weight;
                    pq.push({dist[child], child});
                }
            }
        }
    }

    for (int i = 0; i < q - 1; i++){
        vans[queries[i + 1].second] = min(vans[queries[i + 1].second], vans[queries[i].second]);
    }
    for (int i = 0; i < q; i++){
        cout << (vans[i] == INF ? -1 : vans[i]) << '\n';
    }

    /*
    2 graphs:
    * 1 from the start with both Z = 1 and Z = 2
    * 1 from the end with only Z = 2
    
    setiap kali update suatu node di graph 1, kita add ke ans dari waktu itu
    lalu prefix min
    */
}