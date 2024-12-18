#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u][v]++;
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, 0));
    dp[0][1] = 1;
    for (int mask = 2; mask < (1 << n); mask++){
        if (!(mask & 1)) continue;
        for (int i = 0; i < n; i++){
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++){
                if (i == j || !(mask & (1 << j))) continue;
                dp[i][mask] = (dp[i][mask] + adj[j][i] * dp[j][mask ^ (1 << i)]) % MOD;
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}