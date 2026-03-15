#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    int m; cin >> m;
    for (int _ = 0; _ < m; _++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[v][u] = min(adj[v][u], w);
    }
    for (int node = 0; node < n; node++){
        adj[node][node] = 0;
    }

    int dp[n][n][k + 1][2];
    for (int l = 0; l < n; l++){
        for (int r = 0; r < n; r++){
            for (int i = 0; i <= k; i++){
                dp[l][r][i][0] = INF;
                dp[l][r][i][1] = INF;
            }
        }
    }

    for (int len = 1; len <= n; len++){
        for (int l = 0; l < n - len + 1; l++){
            int r = l + len - 1;
            if (len == 1){
                dp[l][r][1][0] = 0;
                dp[l][r][1][1] = 0;
                continue;
            }
            for (int i = 2; i <= k; i++){
                for (int ll = l + 1; ll <= r; ll++){
                    dp[l][r][i][0] = min({
                        dp[l][r][i][0],
                        dp[ll][r][i - 1][0] + adj[ll][l],
                        dp[ll][r][i - 1][1] + adj[r][l]
                    });
                }
                for (int rr = l; rr <= r - 1; rr++){
                    dp[l][r][i][1] = min({
                        dp[l][r][i][1],
                        dp[l][rr][i - 1][0] + adj[l][r],
                        dp[l][rr][i - 1][1] + adj[rr][r]
                    });
                }
            }
        }
    }
    
    int ans = INF;
    for (int l = 0; l < n; l++){
        for (int r = l; r < n; r++){
            ans = min(ans, dp[l][r][k][0]);
            ans = min(ans, dp[l][r][k][1]);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}