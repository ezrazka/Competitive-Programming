#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; v++){
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }

    vector<int> dp(n, INF);
    auto dfs = [&](auto self, int node) -> void {
        vector<int> c;
        for (int child : adj[node]){
            self(self, child);
            c.push_back(dp[child]);
        }
        sort(c.begin(), c.end());

        if (adj[node].size() == 0){
            dp[node] = 0;
            return;
        }

        if (adj[node].size() == 1){
            dp[node] = *max_element(c.begin(), c.end()) + 1;
            return;
        }

        for (int i = 0; i + 1 < c.size(); i++){
            int left = c[i] + (__lg(i) + 1);
            int right = c.back() + (__lg(c.size() - i - 2) + 1);
            dp[node] = min(dp[node], max(left, right) + 1);
        }
    };
    dfs(dfs, 0);

    cout << dp[0] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    
        solve();
    return 0;
}