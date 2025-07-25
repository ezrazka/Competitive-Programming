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
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i]; c[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<map<int, int>> dp(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        dp[node][c[node]] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                if (dp[node].size() < dp[child].size()){
                    swap(dp[node], dp[child]);
                }
                for (auto [key, val] : dp[child]){
                    ans += dp[node][key] * val;
                    if (key != c[node]){
                        dp[node][key] += val;
                    }
                }
                dp[node][c[node]] = 1;
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}