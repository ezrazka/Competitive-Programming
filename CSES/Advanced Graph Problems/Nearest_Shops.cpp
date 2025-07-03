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
    vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(2, {-1, -1}));
    queue<pair<int, int>> q;
    for (int i = 0; i < k; i++){
        int x; cin >> x; x--;
        dist[x][0] = {0, x};
        q.push({0, x});
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (!q.empty()){
        auto [type, node] = q.front(); q.pop();
        auto [d, root] = dist[node][type];

        for (int child : adj[node]){
            if (dist[child][0].fi == -1){
                dist[child][0] = {d + 1, root};
                q.push({0, child});
            } else if (dist[child][1].fi == -1 && dist[child][0].se != root){
                dist[child][1] = {d + 1, root};
                q.push({1, child});
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << dist[i][dist[i][0].se == i].fi << " \n"[i == n - 1];
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