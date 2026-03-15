#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> c(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> c[i] >> p[i];
    }

    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(101, -INF));
    dp[0][100] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 100; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j - p[i + 1] >= 0){
                dp[i + 1][j - p[i + 1]] = max(dp[i + 1][j - p[i + 1]], dp[i][j] + j * c[i + 1]);
            } else {
                ans = max(ans, dp[i][j] + j * c[i + 1]);
            }
        }
    }

    for (int i = 0; i <= 100; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << fixed << setprecision(10) << ((ld) ans / 100) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}