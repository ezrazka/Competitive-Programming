#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    int ans = 0;
    queue<int> q;
    vector<int> dp(n);
    for (int node = 0; node < n; node++){
        if (indegree[node] == 0){
            q.push(node);
            dp[node] = 0;
            ans = max(ans, dp[node]);
        }
    }

    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int child : adj[node]){
            if (--indegree[child] == 0){
                q.push(child);
            }
            dp[child] = max(dp[child], dp[node] + 1);
            ans = max(ans, dp[child]);
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