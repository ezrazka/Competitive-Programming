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
    vector<vector<int16_t>> table(n + 1, vector<int16_t>(n + 1, -1));
    for (int i = n - 1; i >= 0; i--) {
        vector<bool> vis(n + 1);
        int len = 0, mn = n, mx = 1;
        for (int j = i; j < n; j++) {
            if (vis[a[j]]) break;
            len++, mn = min(mn, a[j]), mx = max(mx, a[j]);
            vis[a[j]] = true;
            if (len == mx - mn + 1) {
                if (table[mn][mx] == -1) table[mn][mx] = i;
                if (mx + len <= n && table[mn + len][mx + len] >= i + len) ans = max(ans, len);
                if (mn - len >= 1 && table[mn - len][mx - len] >= i + len) ans = max(ans, len);
            }
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
