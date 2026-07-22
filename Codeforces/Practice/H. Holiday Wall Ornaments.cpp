#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(n - m + 2, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= min(i, m - 1); j++) {
            for (int k = 0; k <= i - m + 1; k++) {
                { // matching
                    int jj = 
                    dp[i + 1][...][k + 1] = min(dp[i + 1][...][k + 1], dp[i][j][k] + ());
                }
                { // not matching
                    dp[i + 1][...][k] = min();
                }
            }
        }
    }

    for (int k = 0; k <= n - m + 1; k++) {
        int ans = INF;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n][j][k]);
        }
        cout << (ans == INF ? -1 : ans) << " \n"[k == n - m + 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
