#include <bits/stdc++.h>
#include <numeric>
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

    vector<int> v;
    for (int i = 0, cnt = 0; i < n; i++) {
        if (i + 1 < n && a[i] != a[i + 1]) cnt++;
        if ((i == n - 1 || good[i + 1]) && cnt > 0) v.push_back(cnt), cnt = 0;
    }
    debughere;
    for (int x : v) cout << x << ' ';
    cout << '\n';
    debughere;
    if (v.empty()) return cout << "0\n", void();
    int sum = accumulate(v.begin(), v.end(), 0ll);
    int mx = *max_element(v.begin(), v.end());
    int ans = max(0ll, mx - (sum - mx));
    if (k == 1 && (ans & 1)) ans++;
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
