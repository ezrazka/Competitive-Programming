#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = 1, dp[1][1] = 1;
    for (int i = 2; i <= n; i++){
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) dp[i][0] += dp[i - 1][0], dp[i][1] += dp[i - 1][1];
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) dp[i][0] += dp[i - 1][1], dp[i][1] += dp[i - 1][0];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}