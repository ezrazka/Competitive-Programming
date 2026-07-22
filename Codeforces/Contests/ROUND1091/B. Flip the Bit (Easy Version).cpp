#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> good(n);
    for (int i = 0; i < k; i++) {
        int x; cin >> x; x--;
        good[x] = true;
    }

    int ans = n;
    {
        int r = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) r++;
        }
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (good[i]) ans = min(ans, max(l, r));
            if (i + 1 < n && a[i] != a[i + 1]) l++, r--;
        }
    }
    if (ans & 1) ans++;
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
