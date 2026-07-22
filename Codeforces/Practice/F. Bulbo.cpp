#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int INF = 1e18;

void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<int> v{x};
    for (int i = 1; i <= n; i++) {
        v.push_back(a[i].first);
        v.push_back(a[i].second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();

    x = lower_bound(v.begin(), v.end(), x) - v.begin();
    for (int i = 1; i <= n; i++) {
        a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin();
        a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
    }

    vector<int> dp(m, INF), ndp(m, INF);
    dp[x] = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> pref(m), suff(m);
        for (int j = 0; j < m; j++) {
            pref[j] = dp[j] - v[j];
            suff[j] = dp[j] + v[j];
        }
        for (int j = 1; j < m; j++) pref[j] = min(pref[j], pref[j - 1]);
        for (int j = m - 2; j >= 0; j--) suff[j] = min(suff[j], suff[j + 1]);
        for (int j = 0; j < m; j++) {
            int move_cost = min(
                pref[j] + v[j],
                suff[j] - v[j]
            );
            int distance_cost;
            if (v[j] < v[a[i].first]) distance_cost = v[a[i].first] - v[j];
            else if (v[j] > v[a[i].second]) distance_cost = v[j] - v[a[i].second];
            else distance_cost = 0;
            ndp[j] = min(ndp[j], move_cost + distance_cost);
        }
        dp = ndp;
        fill(ndp.begin(), ndp.end(), INF);
    }

    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
