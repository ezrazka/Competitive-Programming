#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

const int MOD = 998244353;
const int N = 2e5;

int n, ones;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int p(int filled) {
    if (filled == ones) return 0;
    int left = ones - filled;
    int right = ones - filled;
    int total = (n * (n - 1) / 2) % MOD;
    return ((left * right) % MOD * inv(total)) % MOD;
}

int dp(int filled) {
    if (filled == ones) return 0;
    // dp[i] = 1 + dp[i] * (1 - p) + dp[i + 1] * p;
    // dp[i] = 1/p + dp[i + 1];
    return (dp(filled + 1) + inv(p(filled))) % MOD;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ones = count(a.begin(), a.end(), 1);

    int filled = count(a.end() - ones, a.end(), 1);
    cout << dp(filled) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
