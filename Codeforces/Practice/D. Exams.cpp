#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool ok = true;

        vector<pair<int, int>> times(m + 1, {-1, -1});
        for (int i = 1; i <= mid; i++) {
            times[a[i]] = {i, b[a[i]]};
        }
        times[0] = {0, 0};
        sort(times.begin(), times.end());

        if (times[0].first == -1) {
            ok = false;
        }

        int sum = 0;
        for (int i = 1; i <= m; i++) {
            sum += times[i].first - times[i - 1].first - 1;
            sum -= times[i].second;
            if (sum < 0) {
                ok = false;
            }
        }

        if (ok) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
