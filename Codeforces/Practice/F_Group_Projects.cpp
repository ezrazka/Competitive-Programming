#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    int m = n / 2;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    int dp[n + 1][m + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            for (int k = 0; k <= x; k++){
                int diff = a[i] - a[i - 1];
                if (j - 1 >= 0 && k - diff * (j - 1) >= 0) dp[i][j][k] += dp[i - 1][j - 1][k - diff * (j - 1)];
                if (k - diff * j >= 0) dp[i][j][k] += dp[i - 1][j][k - diff * j] * (j + 1);
                if (j + 1 <= m && k - diff * (j + 1) >= 0) dp[i][j][k] += dp[i - 1][j + 1][k - diff * (j + 1)] * (j + 1);
                dp[i][j][k] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= x; i++){
        ans += dp[n][0][i];
        ans %= MOD;
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