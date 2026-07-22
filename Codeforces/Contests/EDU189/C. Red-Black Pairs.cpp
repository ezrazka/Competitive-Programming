#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<vector<char>> a(3, vector<char>(n + 1));
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + (a[1][i] != a[2][i]);
        if (i - 2 >= 0) {
            dp[i] = min(dp[i], dp[i - 2] + (a[1][i - 1] != a[1][i]) + (a[2][i - 1] != a[2][i]));
        }
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
