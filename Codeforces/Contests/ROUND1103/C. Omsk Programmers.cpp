#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int a, b, x; cin >> a >> b >> x;

    int ans = LLONG_MAX, cnt = 0;
    while (a || b) {
        if (a > b) swap(a, b);
        ans = min(ans, cnt + (b - a));
        b /= x, cnt++;
    }
    ans = min(ans, cnt);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
