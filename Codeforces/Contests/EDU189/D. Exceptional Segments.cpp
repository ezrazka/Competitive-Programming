#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

const int MOD = 998244353;

void solve() {
    int n, x; cin >> n >> x;

    int left_1 = ((x - 1) + 3) / 4 % MOD;
    int left_3 = ((x - 1) + 1) / 4 % MOD;
    int right_1 = ((n + 3) / 4 - left_1) % MOD;
    int right_3 = ((n + 1) / 4 - left_3) % MOD;
    int ans = ((left_1 * right_1) % MOD + ((left_3 + 1) * right_3) % MOD) % MOD;
    cout << ans << '\n';
    // int xor_product = 0;
    // for (int i = 1; i <= n; i++) {
    //     xor_product ^= i;
    //     cout << xor_product << " \n"[i == n];
    // }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
