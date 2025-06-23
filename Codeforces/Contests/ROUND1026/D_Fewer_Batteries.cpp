#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w, u--, v--;
        adj[u].push_back({v, w});
    }

    int l = 1, r = 1e9, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;

        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int node = 0; node < n; node++){
            if (dp[node] == -1) continue;
            dp[node] += v[node];
            dp[node] = min(dp[node], mid);
            for (auto [child, weight] : adj[node]){
                if (dp[node] >= weight){
                    dp[child] = max(dp[child], dp[node]);
                    dp[child] = min(dp[child], mid);
                }
            }
        }

        if (dp[n - 1] == -1){
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
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