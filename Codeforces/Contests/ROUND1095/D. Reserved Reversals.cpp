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

    int odds = 0;
    for (int i = 0; i < n; i++) {
        odds += a[i] & 1;
    }

    if (odds == 0 || odds == n) {
        cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
        return;
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    if ((mn & 1) != (mx & 1)) {
        cout << "YES\n";
        return;
    }

    int mn_diff = n + 1, mx_diff = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & 1) != (mn & 1)) {
            mn_diff = min(mn_diff, a[i]);
            mx_diff = max(mx_diff, a[i]);
        }
    }

    int argmx = 0, argmn = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx_diff) {
            argmx = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < mn_diff) {
            argmn = i;
            break;
        }
    }

    cout << (argmx < argmn ? "NO\n" : "YES\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
