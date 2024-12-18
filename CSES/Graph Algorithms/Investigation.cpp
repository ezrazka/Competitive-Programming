#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define ar array<int, 4>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w);
    }

    vector<int> dist(n, 1e18), cnt(n, 0), mn(n, 1e9), mx(n, -1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0] = 0, cnt[0] = 1, mn[0] = 0, mx[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();
        if (dist[node] < d) continue;

        for (auto [child, w] : adj[node]){
            if (dist[child] == d + w){
                cnt[child] = (cnt[child] + cnt[node]) % MOD;
                mn[child] = min(mn[child], mn[node] + 1);
                mx[child] = max(mx[child], mx[node] + 1);
            } else if (dist[child] > d + w){
                dist[child] = d + w;
                cnt[child] = cnt[node];
                mn[child] = mn[node] + 1;
                mx[child] = mx[node] + 1;
                pq.emplace(dist[child], child);
            }
        }
    }
    cout << dist[n - 1] << ' ' << cnt[n - 1] << ' ' << mn[n - 1] << ' ' << mx[n - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}