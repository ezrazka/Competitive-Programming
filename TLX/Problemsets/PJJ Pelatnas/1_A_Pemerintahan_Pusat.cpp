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
    for (int u = 1; u < n; u++){
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> w(n), d(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<vector<int>> dp(n, vector<int>(2));
    auto dfs = [&](auto self, int node, int parent) -> void {
        dp[node][0] = -w[node];
        dp[node][1] = w[node];
        vector<int> children;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                children.push_back(child);
            }
        }
        sort(children.begin(), children.end(), [&](int i, int j){
            return dp[i][1] - dp[i][0] < dp[j][1] - dp[j][0];
        });
        for (int i = 0; i < children.size(); i++){
            if (i < d[node]){
                dp[node][1] += dp[children[i]][0];
            } else {
                dp[node][1] += dp[children[i]][1];
            }
            if (children.size() - 1 - i < d[node]){
                dp[node][0] += dp[children[i]][1];
            } else {
                dp[node][0] += dp[children[i]][0];
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}