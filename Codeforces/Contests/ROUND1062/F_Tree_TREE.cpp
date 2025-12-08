#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n), sz(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        sz[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                sz[node] += sz[child];
                dp[node] += dp[child];
            }
        }
        if (sz[node] >= k) dp[node]++;
    };
    dfs(dfs, 0, -1);

    vector<int> dp_reroot(n);
    auto dfs_reroot = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                dp_reroot[child] = dp_reroot[node] + ((n - sz[child] >= k) - 1) + (1 - (sz[child] >= k));
                self(self, child, node);
            }
        }
    };
    dp_reroot[0] = dp[0];
    dfs_reroot(dfs_reroot, 0, -1);

    cout << accumulate(dp_reroot.begin(), dp_reroot.end(), 0ll) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}