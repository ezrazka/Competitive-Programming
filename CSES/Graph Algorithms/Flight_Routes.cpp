#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w);
    }

    vector<int> temp = vector<int>(k, 1e18);
    vector<multiset<int>> dist(n, multiset<int>(temp.begin(), temp.end()));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0].insert(0);
    dist[0].erase(--dist[0].end());
    pq.emplace(0, 0);
    while (!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();
        if (*dist[node].rbegin() < d) continue;

        for (auto [child, w] : adj[node]){
            if (*dist[child].rbegin() > d + w){
                dist[child].insert(d + w);
                dist[child].erase(--dist[child].end());
                pq.emplace(d + w, child);
            }
        }
    }
    
    for (auto d : dist[n - 1]){
        cout << d << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}