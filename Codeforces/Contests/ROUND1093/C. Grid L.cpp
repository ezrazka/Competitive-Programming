#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int p, q; cin >> p >> q;

    int sum = p * 1 + q * 2;
    /* Condition 1
       sum = n(m + 1) + m(n + 1)
       sum = 2nm + n + m;
       sum = m(2n + 1) + n
       m = (sum - n)/(2n + 1)

       find any positive n such that m is a postive integer
    */
    /* Condition 2
        p >= min(n, m)
    */
    for (int n = 1; n <= p; n++) {
        int m = (sum - n + (2 * n + 1) - 1) / (2 * n + 1);
        if (p < min(n, m)) break;
        if ((sum - n) % (2 * n + 1) == 0) {
            cout << n << ' ' << m << '\n';
            return;
        }
    }
    for (int n = p; n >= 1; n--) {
        int m = (sum - n) / (2 * n + 1);
        if (p < min(n, m)) break;
        if ((sum - n) % (2 * n + 1) == 0) {
            cout << n << ' ' << m << '\n';
            return;
        }
    }
    cout << "-1\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
