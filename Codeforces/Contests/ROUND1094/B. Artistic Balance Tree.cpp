#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), x(m);
    vector<int> odds, evens;
    for (int i = 0; i < n; i++) cin >> a[i], (i & 1 ? (odds.push_back(a[i]), 1) : (evens.push_back(a[i]), 1));
    for (int i = 0; i < m; i++) cin >> x[i], x[i]--;
    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    bool odd_done = false, even_done = false;
    int ans = accumulate(a.begin(), a.end(), 0ll);
    for (int i : x) {
        if (i & 1) {
            if (!odds.empty() && !(odd_done && odds.back() < 0)) {
                ans -= odds.back();
                odds.pop_back();
                odd_done = true;
            }
        } else {
            if (!evens.empty() && !(even_done && evens.back() < 0)) {
                ans -= evens.back();
                evens.pop_back();
                even_done = true;
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
