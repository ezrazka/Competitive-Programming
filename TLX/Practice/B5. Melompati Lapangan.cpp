#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MOD = 1e9 + 7;

const std::size_t N = 2047;
const std::size_t M = 2047;

ll dp[N + 1][M + 1];
int a[N + 1][M + 1];

int get_int() {
    int r = 0; bool neg = false; char c;
    while (true) {
        c = getchar_unlocked();
        if (c == ' ' || c == '\n') continue;
        if (c == '-') { neg = true; continue; }
        else if (c < '0' || c > '9') continue;
        else break;
    }
    r = c - '0';
    while (true) {
        c = getchar_unlocked();
        if (c >= '0' && c <= '9') r = (r << 3) + (r << 1) + (c - '0');
        else break;
    }
    if (neg) r = -r;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::size_t n = get_int(), m = get_int();
    for (std::size_t i = n; i >= 1; i--) {
        for (std::size_t j = m; j >= 1; j--) {
            a[i][j] = get_int();
        }
    }

    dp[1][1] = 1;
    const std::size_t limit = 2048;
    for (std::size_t i = 1; i <= n; i++) {
        for (std::size_t j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            if (a[i][j]) {
                const std::size_t ii = i - a[i][j] - 1;
                const std::size_t jj = j - a[i][j] - 1;
                dp[i][j] <<= 1;
                if (ii < limit) dp[i][j] -= dp[ii][j];
                if (jj < limit) dp[i][j] -= dp[i][jj];
                if (ii < limit && jj < limit) dp[i][j] += dp[ii][jj];
            }
            dp[i][j] %= MOD;
        }
    }

    int ans = (dp[n][m] - dp[n - 1][m] - dp[n][m - 1] + dp[n - 1][m - 1]) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}
