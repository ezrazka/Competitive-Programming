#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> ord_a(n), ord_b(m);
    iota(ord_a.begin(), ord_a.end(), 0);
    sort(ord_a.begin(), ord_a.end(), [&](int i, int j) { return a[i] < a[j]; });
    iota(ord_b.begin(), ord_b.end(), 0);
    sort(ord_b.begin(), ord_b.end(), [&](int i, int j) { return b[i] < b[j]; });

    int ans1 = 0, ans2 = 0;
    vector<int> vans1(m), vans2(n);
    vector<bool> vis_a(n), vis_b(m);
    for (int bit = 0; bit <= 30; bit++) {
        for (int i = 0, j = 0; i < n; i++) {
            if (vis_a[i]) continue;
            while (j < m && (vis_b[j] || a[ord_a[i]] > b[ord_b[j]])) j++;
            if (j == m) break;
            if (a[ord_a[i]] == b[ord_b[j]]) {
                ans1++, ans2 += bit, vans1[ord_b[j]] = bit, vans2[ord_a[i]] = ord_b[j] + 1;
                vis_a[i] = true, vis_b[j++] = true;
            }
        }
        for (int j = 0; j < m; j++) b[j] = (b[j] + 1) / 2;
    }
    cout << ans1 << ' ' << ans2 << '\n';
    for (int j = 0; j < m; j++) cout << vans1[j] << " \n"[j == m - 1];
    for (int i = 0; i < n; i++) cout << vans2[i] << " \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
