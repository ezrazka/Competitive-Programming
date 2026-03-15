#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n; n++;
    vector<vector<int>> adj(n);
    for (int u = 1; u < n; u++){
        int v1, v2; cin >> v1 >> v2;
        if (v1 == 0 && v2 == 0) continue;
        adj[u].push_back(v1);
        adj[v1].push_back(u);
        adj[u].push_back(v2);
        adj[v2].push_back(u);
    }
    adj[0].push_back(1);
    adj[1].push_back(0);

    vector<int> sz(n);
    {
        auto dfs = [&](auto self, int node, int parent) -> void {
            sz[node] = 1;
            for (int child : adj[node]){
                if (child != parent){
                    self(self, child, node);
                    sz[node] += sz[child];
                }
            }
        };
        dfs(dfs, 1, 0);
    }
    vector<int> dp(n);
    {
        auto dfs = [&](auto self, int node, int parent) -> void {
            for (int child : adj[node]){
                if (child != parent){
                    dp[child] = (dp[node] + 2 * (sz[child] - 1) + 1) % MOD;
                    self(self, child, node);
                }
            }
        };
        dp[1] = (2 * (sz[1] - 1) + 1) % MOD;
        dfs(dfs, 1, 0);
    }

    for (int node = 1; node < n; node++){
        cout << dp[node] << " \n"[node == n - 1];
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