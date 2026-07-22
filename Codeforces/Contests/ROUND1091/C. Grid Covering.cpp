#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    auto solve = [](int n, int m, int a, int b) {
        return __gcd(a, n) == 1 && __gcd(b, m) == 1 && __gcd(n, m) <= 2;
    };

    cout << (solve(n, m, a, b) ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
