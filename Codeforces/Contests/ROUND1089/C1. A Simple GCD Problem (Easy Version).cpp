#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++){
        int x = (i - 1 < 0 ? 0 : __gcd(a[i - 1], a[i]));
        int y = (i >= n - 1 ? 0 : __gcd(a[i], a[i + 1]));
        if (x == 0) x = y;
        if (y == 0) y = x;
        if (x * y / __gcd(x, y) < a[i]) ans++;
    }
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
