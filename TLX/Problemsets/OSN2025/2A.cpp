#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][0] = __lg(a[1]);
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] * __lg(a[i])) % MOD;
        dp[i][1] = (
            dp[i - 1][0] * (i < n && __lg(a[i]) == __lg(a[i + 1]))
            + dp[i - 1][1]
        ) % MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
