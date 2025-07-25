#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    pair<int, int> x, y;
    cin >> x.fi >> x.se >> y.fi >> y.se;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int mx = *max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0ll);
    int min_dist = max(0ll, mx - (sum - mx));
    int max_dist = sum;

    int distance = (y.fi - x.fi) * (y.fi - x.fi) + (y.se - x.se) * (y.se - x.se);
    cout << (min_dist * min_dist <= distance && distance <= max_dist * max_dist ? "Yes\n" : "No\n");
    // no number can be larger than the sum of the rest


    // int sum = 0;
    // for (int i = 0; i < n; i++){
    //     sum += v[i];
    // }
    // sum *= sum;

    // int distance = (y.fi - x.fi) * (y.fi - x.fi) + (y.se - x.se) * (y.se - x.se);
    // cout << (sum >= distance && (n == 1 && sum == distance || n > 1) ? "Yes\n" : "No\n");
    // as long as the sum of distances is at least distance AND (n == 1 AND sum = dist OR n > 1)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}