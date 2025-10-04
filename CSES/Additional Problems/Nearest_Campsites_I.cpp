#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
    for (int i = 0; i < m; i++) cin >> b[i].fi >> b[i].se;

    vector<int> sums, diffs;
    for (int i = 0; i < n; i++){
        sums.push_back(a[i].fi + a[i].se);
        diffs.push_back(a[i].fi - a[i].se);
    }
    sort(sums.begin(), sums.end());
    sort(diffs.begin(), diffs.end());
    
    int mx = 0;
    for (int i = 0; i < m; i++){
        int sum = b[i].fi + b[i].se;
        int diff = b[i].fi - b[i].se;
        int mn_sum = 1e18, mn_diff = 1e18;
        {
            int gte = lower_bound(sums.begin(), sums.end(), sum) - sums.begin();
            mn_sum = min(mn_sum, abs(sum - sums[gte]));
            if (gte - 1 >= 0) mn_sum = min(mn_sum, abs(sum - sums[gte - 1]));
        }
        {
            int gte = lower_bound(diffs.begin(), diffs.end(), diff) - diffs.begin();
            mn_diff = min(mn_diff, abs(diff - diffs[gte]));
            if (gte - 1 >= 0) mn_diff = min(mn_diff, abs(diff - diffs[gte - 1]));
        }
        cout << mn_sum << ' ' << mn_diff << '\n';
        mx = max({mx, mn_sum, mn_diff});
    }
    cout << mx << '\n';
    // fails cuz i consider x + y and x - y separate even though they should belong to the same point
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}