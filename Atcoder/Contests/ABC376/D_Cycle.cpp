#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }

    vector<int> dp(n, 1e18);
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int child : adj[node]){
            if (child != 0 && dp[child] == 1e18){
                q.push(child);
            }
            if (node == 0) dp[child] = 1;
            else dp[child] = min(dp[child], dp[node] + 1);
        }
    }
    cout << (dp[0] == 1e18 ? -1 : dp[0]) << '\n';
}