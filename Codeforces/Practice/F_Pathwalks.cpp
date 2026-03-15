#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<map<int, int>> dp(n);
    for (int node = 0; node < n; node++){
        dp[node][0] = 0;
    }

    while (m--){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        int edges_u = prev(dp[u].upper_bound(w))->second;
        int edges_v = prev(dp[v].lower_bound(w))->second;
        if (edges_v < edges_u + 1 && (dp[v].find(w) == dp[v].end() || dp[v][w] < edges_u + 1)){
            vector<map<int, int>::iterator> to_erase;
            for (auto it = dp[v].lower_bound(w); it != dp[v].end(); it++){
                if (edges_u + 1 < it->second) break;
                to_erase.push_back(it);
            }
            for (auto it : to_erase){
                dp[v].erase(it);
            }
            dp[v][w] = edges_u + 1;
        }
    }
    
    int ans = 0;
    for (int node = 0; node < n; node++){
        for (auto [key, val] : dp[node]){
            ans = max(ans, val);
        }
    }
    cout << ans << '\n';
    /*
    each node stores a map
    (key, value) -> (last val in LIS, edge count so far)
    since if we can grab key X, we can also grab keys 1..X-1,
    we should keep the map monotonically increasing (by values)

    how do we handle (1) cycles, (2) self loops, and (3) multiple edges?
    they are not an issue since we have a fixed edge evaluation order
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