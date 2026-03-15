#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> pleasure(n + 1, vector<int>(m + 1));
    { // pleasure to be reached from cell (1, 1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (i == 1 && j == 1){
                    dp[i][j] = a[i][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
                }
                pleasure[i][j] += dp[i][j];
            }
        }
    }
    { // pleasure to reach cell (n, m)
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, -INF));
        for (int i = n; i >= 1; i--){
            for (int j = m; j >= 1; j--){
                if (i == n && j == m){
                    dp[i][j] = a[i][j];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + a[i][j];
                }
                pleasure[i][j] += dp[i][j];
            }
        }
    }
    
    // remove double counting
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pleasure[i][j] -= a[i][j];
        }
    }

    // pref[i][j] = maximum value of first j elements of pleasure[i][j] on diagonal i
    // suff[i][j] = maximum value of last  j elements of pleasure[i][j] on diagonal i
    vector<vector<int>> pref(n + m, vector<int>(min(n, m) + 1, -INF));
    vector<vector<int>> suff(n + m, vector<int>(min(n, m) + 1, -INF));
    {
        for (int d = 1; d <= n + m - 1; d++){
            for (int k = 1;; k++){
                int i = min(n, d) - k + 1, j = d - i + 1;
                if (i < 1 || i > n || j < 1 || j > m) break;
                pref[d][k] = max(pref[d][k - 1], pleasure[i][j]);
            }
        }
        for (int d = 1; d <= n + m - 1; d++){
            for (int k = 1;; k++){
                int j = min(m, d) - k + 1, i = d - j + 1;
                if (i < 1 || i > n || j < 1 || j > m) break;
                suff[d][k] = max(suff[d][k - 1], pleasure[i][j]);
            }
        }
    }


    int ans = INF;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int d = i + j - 1;
            int cur = max(
                pleasure[i][j] - 2 * a[i][j],
                max(pref[d][min(n - i, j - 1)], suff[d][min(i - 1, m - j)])
            );
            ans = min(ans, cur);
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