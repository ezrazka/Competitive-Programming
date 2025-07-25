#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(2));
    auto dfs = [&](auto self, int node, int parent) -> void {
        dp[node][0] = 1;
        dp[node][1] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                dp[node][0] = (dp[node][0] * dp[child][1]) % MOD;
                dp[node][1] = (dp[node][1] * (dp[child][0] + dp[child][1])) % MOD;
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}