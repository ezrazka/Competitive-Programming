#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m; cin >> n >> m;

    int ans = 0;
    for (int p = 1; p * p <= n; p++) {
        for (int q = 1; q * q <= m; q++) {
            if (gcd(p, q) == 1) {
                ans += min(n / p, m / q) / (p + q);
            }
        }
    }
    cout << ans << '\n';

    /*
        b * gcd(a, b) % (a + b) == 0
        {set_of_factors(a + b)} is a subset of {set_of_factors(b) - set_of_factors(a)}

        Ideas:
        * fix a?
        * fix b?
        * fix a + b?
        * fix gcd(a, b)? seems like the way to go
        
        fix gcd(a, b)
        -> a and b must be a multiple of it
        -> b % ((a + b) / gcd(a, b)) == 0
        -> let a / gcd be x, let b / gcd be y
        -> find the number of ways where
            b % (x + y) == 0 and
            gcd(x, y) == 1 and
            x * b / y <= n and
            b % y == 0 and
        -> for each b, for each factor of b y, 

        b * gcd(a, b) % (a + b) == 0
        qd * d % (pd + qd)
        qd % (p + q) == 0

    */
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
