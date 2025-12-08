#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int INF = 1e14;

void solve(){
    int n; cin >> n;
    vector<int> v(n), c(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    auto v2 = v;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (int i = 0; i < n; i++){
        v[i] = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
    }

    vector<int> dp(n, INF), ndp(n, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        int mn = INF;
        for (int j = 0; j < n; j++){
            mn = min(mn, dp[j]);
            ndp[j] = min(ndp[j], mn + c[i - 1] * (j != v[i - 1]));
        }
        swap(dp, ndp);
        fill(ndp.begin(), ndp.end(), INF);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}