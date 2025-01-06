#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1e9;
    for (int node = 0; node < n; node++){
        sort(adj[node].begin(), adj[node].end(), [&](int i, int j){
            return adj[i].size() < adj[j].size();
        });
        int x = adj[node].size();
        for (int child : adj[node]){
            int y = adj[child].size() - 1;
            if (y != 0){
                ans = min(ans, n - (1 + x + x * y));
            }
            x--;
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