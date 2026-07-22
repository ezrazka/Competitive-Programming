#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int A = 1e6;
constexpr int B = __lg(A) + 1;

void solve() {
    int n; cin >> n;
    vector<int> a(n), freq(1 << B);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<array<int, 3>> vans(n);
    /*
        dp[mask][i] -> SOS of mask, but only where the i smallest bits are free
        e.g.
        11010|101 --- mask = 11010101, i = 3
        `dp[0b11010101][3] = A[0b11010'000] + A[0b11010'001] + A[0b11010'100] + A[0b11010'101]`
    */
    vector<vector<int>> dp(1 << B, vector<int>(B + 1));
    { // 1. count subsets
        for (int mask = 0; mask < (1 << B); mask++) {
            dp[mask][0] = freq[mask];
            for (int i = 1; i <= B; i++) {
                dp[mask][i] += dp[mask][i - 1];
                if (mask & (1 << (i - 1))) dp[mask][i] += dp[mask ^ (1 << (i - 1))][i - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            vans[i][0] = dp[a[i]][B];
        }
    }
    { // count supersets
        for (int mask = (1 << B) - 1; mask >= 0; mask--) {
            dp[mask][0] = freq[mask];
            for (int i = 1; i <= B; i++) {
                dp[mask][i] = dp[mask][i - 1];
                if (!(mask & (1 << (i - 1)))) dp[mask][i] += dp[mask | (1 << (i - 1))][i - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            vans[i][1] = dp[a[i]][B];
        }
    }
    { // count intersects
        for (int not_mask = 0; not_mask < (1 << B); not_mask++) {
            const int mask = not_mask ^ ((1 << B) - 1);
            dp[mask][0] = freq[not_mask];
            for (int i = 1; i <= B; i++) {
                dp[mask][i] = dp[mask][i - 1];
                if (not_mask & (1 << (i - 1))) dp[mask][i] += dp[mask | (1 << (i - 1))][i - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            vans[i][2] = n - dp[a[i]][B];
        }
    }

    for (auto [x, y, z] : vans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }

    /*
        1. count how many: y is a subset of x
            -> SOS DP over freq
        2. count how many: y is a superset of x
            -> SOS DP over freq
            -> the catch:
                iterate from the end, removing bits if not in mask
        3. count how many: y intersects x
            -> SOS DP over freq
            -> the catch:
                calculate the complement,
                the "subset" is the subset of its NOT
    */
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
