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

    // jika tidak ketemu, jawab -1
    // awalnya kita kasih nilai besar "tak hingga" baru di akhir ganti dengan -1
    vector<int> dp(x + 1, 1e9); // dp[0]–dp[n]
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        // 1. dp[-1] -> akan menghasilkan "undefined behavior"
        for (int j : c) { // daripada menghitung 1–6, kita hitung nilai-nilai dalam array "c"
            if (i - j >= 0) {
                // dp[i] += dp[i - j];
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
        dp[i] %= MOD;
        // dp[i] = dp[i] % MOD;
    }

    if (dp[x] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
    // syntax singkat dari if
    // cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
    // 5 + 5 + 1 = 11
}