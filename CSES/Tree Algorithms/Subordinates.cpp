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
    for (int v = 1; v < n; v++){
        int u; cin >> u; u--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        dp[node] = 1;
        for (int child : adj[node]){
            if (child == parent) continue;
            self(self, child, node);
            dp[node] += dp[child];
        }
    };
    dfs(dfs, 0, -1);

    for (int node = 0; node < n; node++){
        cout << dp[node] - 1 << " \n"[node == n - 1];
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