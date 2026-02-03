#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (accumulate(b.begin(), b.end(), 0) != accumulate(c.begin(), c.end(), 0)){
        cout << "-1\n";
        return;
    }

    vector<int> min_cost(n);
    {
        auto dfs = [&](auto self, int node, int parent) -> void {
            for (int child : adj[node]){
                if (child != parent){
                    min_cost[child] = min(min_cost[node], a[child]);
                    self(self, child, node);
                }
            }
        };
        min_cost[0] = a[0];
        dfs(dfs, 0, -1);
    }

    int ans = 0;
    {
        vector<vector<int>> dp(n, vector<int>(2));
        auto dfs = [&](auto self, int node, int parent) -> void {
            if (b[node] != c[node]) dp[node][b[node]]++;
            for (int child : adj[node]){
                if (child != parent){
                    self(self, child, node);
                    dp[node][0] += dp[child][0];
                    dp[node][1] += dp[child][1];
                }
            }
            int pairs = min(dp[node][0], dp[node][1]);
            ans += (2 * pairs) * min_cost[node];
            dp[node][0] -= pairs, dp[node][1] -= pairs;
        };
        dfs(dfs, 0, -1);
    }
    cout << ans << '\n';

    /*
    Observations:
    * It's invalid iff the number of 1s in B and 1s in C are different
    * After eliminating invalid cases, the number of wrong digits of 0 and of 1 are equal
    * The minimum cost of swapping two nodes is the minimum a[i] from the path from root to lca
    * We can either swap:
        1. a wrong digit with a wrong digit
        2. a wrong digit with a right digit, or
            but after doing this, you must still do 1., and combined they are
            always at least as expensive as just doing 1.
        3. a right digit with a right digit
            but this does nothing for a non-zero cost
    * Therefore, we can just solve a pair at a time
    * It's optimal to always exhaust all 0-1 pairs in a subtree, this can be done with DP
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}