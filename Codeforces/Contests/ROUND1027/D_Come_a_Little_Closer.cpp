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
    vector<pair<int, int>> v(n);
    vector<int> vals_x, vals_y;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        vals_x.push_back(x);
        vals_y.push_back(y);
        v[i] = {x, y};
    }
    sort(vals_x.begin(), vals_x.end());
    sort(vals_y.begin(), vals_y.end());
    vals_x.erase(unique(vals_x.begin(), vals_x.end()), vals_x.end());
    vals_y.erase(unique(vals_y.begin(), vals_y.end()), vals_y.end());

    if (n == 1){
        cout << 1 << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        v[i].fi = lower_bound(vals_x.begin(), vals_x.end(), v[i].fi) - vals_x.begin();
        v[i].se = lower_bound(vals_y.begin(), vals_y.end(), v[i].se) - vals_y.begin();
    }

    multiset<int> st_x, st_y;
    for (int i = 0; i < n; i++){
        st_x.insert(v[i].fi);
        st_y.insert(v[i].se);
    }

    int ans = 1e18;
    for (int i = 0; i < n; i++){
        st_x.erase(st_x.find(v[i].fi));
        st_y.erase(st_y.find(v[i].se));
        int l = *st_x.begin(), r = *st_x.rbegin();
        int d = *st_y.begin(), u = *st_y.rbegin();
        int res = (vals_x[r] - vals_x[l] + 1) * (vals_y[u] - vals_y[d] + 1);
        if (res == n - 1) res += min(vals_x[r] - vals_x[l] + 1, vals_y[u] - vals_y[d] + 1);
        ans = min(ans, res);
        st_x.insert(v[i].fi);
        st_y.insert(v[i].se);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}