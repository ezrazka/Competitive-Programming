#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        int gcd = 0, mx = 0, mn = n + 1;
        bool skip = false;
        for (int r = l; r < n; r++) {
            gcd = __gcd(gcd, a[r]);
            mx = max(mx, a[r]);
            mn = min(mn, a[r]);
            if (mx - mn == gcd) ans++;
            if (skip) break;
            if (gcd == 1) skip = true;
        }
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
