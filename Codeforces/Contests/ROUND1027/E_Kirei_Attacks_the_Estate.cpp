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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp_mx(n), dp_mn(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                dp_mx[child] = v[child] - min(0ll, dp_mn[node]);
                dp_mn[child] = v[child] - max(0ll, dp_mx[node]);
                self(self, child, node);
            }
        }
    };
    dp_mx[0] = v[0];
    dp_mn[0] = v[0];
    dfs(dfs, 0, -1);

    for (int node = 0; node < n; node++){
        cout << dp_mx[node] << " \n"[node == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}