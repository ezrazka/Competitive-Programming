#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9 + 7; // variabel yang ditulis secara global secara umum ditulis angka besar

signed main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1); // dp[0]–dp[n]
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        // 1. dp[-1] -> akan menghasilkan "undefined behavior"
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
        dp[i] %= MOD;
        // dp[i] = dp[i] % MOD;
    }
    cout << dp[n] << '\n';
}