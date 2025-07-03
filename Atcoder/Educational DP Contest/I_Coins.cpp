#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<ld> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<vector<ld>> dp(n + 1, vector<ld>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            dp[i][j] = dp[i - 1][j] * (1 - v[i - 1]);
            if (j >= 1){
                dp[i][j] += dp[i - 1][j - 1] * v[i - 1];
            }
        }
    }

    ld ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++){
        ans += dp[n][i];
    }
    cout << fixed << setprecision(10) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}