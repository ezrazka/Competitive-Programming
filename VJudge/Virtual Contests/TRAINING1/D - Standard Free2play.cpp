#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int h, n; cin >> h >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());

    int i = 0;
    while (i < n && i == a[i] - 1) i++;
    i++;

    int ans = 0, cnt = 1;
    for (; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            cnt++;
        } else {
            if (cnt % 2 == 1) ans++;
            cnt = 1;
        }
    }
    if (cnt % 2 == 0) ans++;
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
