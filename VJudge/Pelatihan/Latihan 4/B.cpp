#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9 + 7; // variabel yang ditulis secara global secara umum ditulis angka besar

signed main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> dp(x + 1); // dp[0]–dp[n]
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        // 1. dp[-1] -> akan menghasilkan "undefined behavior"
        // for (int j = 0; j < n; j++) { // daripada menghitung 1–6, kita hitung nilai-nilai dalam array "c"
        //     if (i - c[j] >= 0) {
        //         dp[i] += dp[i - c[j]];
        //     }
        // }
        for (int j : c) { // daripada menghitung 1–6, kita hitung nilai-nilai dalam array "c"
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
        dp[i] %= MOD;
        // dp[i] = dp[i] % MOD;
    }
    cout << dp[x] << '\n';
}