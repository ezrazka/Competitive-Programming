#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
const int INV_2 = 499122177;

void solve(){
    int n, k; cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 2;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= j && i - k >= 0; k++){
                dp[i][j] = (dp[i][j] + dp[i - k][j]) % MOD;
            }
            for (int k = 0; k < j && i - j >= 0; k++){
                dp[i][j] = (dp[i][j] + dp[i - j][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int sum = 0;
        for (int j = 1; j <= min(n, (k + i - 1) / i - 1); j++){
            sum = (sum + dp[n][j]) % MOD;
        }
        ans = (ans + dp[n][i] * sum) % MOD;
    }
    ans = (ans * INV_2) % MOD;
    cout << ans << '\n';

    /*
    1010
    0101
    1010
    0101

    1001
    0110

    ans is 2^(2n - 1) with k > n * n

    let max length of contiguous segment of same color in row 1 be X
    we cannot have >=ceil(k / X) consecutive identical rows

    for each X from 1..n,
        ans += {arrays with max segment length X} *
               {arrays with max segment length <ceil(k / X)}
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}