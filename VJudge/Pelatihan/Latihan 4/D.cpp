#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;

    // 1. antara . atau *, jadi simpan karakter "char"
    // 2. vector<vector<>> -> n * n elemen total
    vector<vector<char>> a(n, vector<char>(n)); // 2 dimensi
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // vector<vector<>> -> (n + 1) * (n + 1) elemen total
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) { // sumber (1, 1)
                dp[i][j] = 1;
            } else if (a[i - 1][j - 1] == '*'){ // ubah lagi ke 0-based indexing, dari 1-based
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n][n] << '\n'; // mencapai (n, n)
}