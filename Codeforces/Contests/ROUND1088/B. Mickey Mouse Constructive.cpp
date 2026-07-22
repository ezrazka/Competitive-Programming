#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int x, y; cin >> x >> y;

    int ans = (x == y);
    for (int i = 1; i <= abs(x - y); i++) {
        if (abs(x - y) % i == 0) ans++;
    }
    cout << ans << '\n';
    for (int i = 0; i < x; i++) cout << 1 << ' ';
    for (int i = 0; i < y; i++) cout << -1 << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
