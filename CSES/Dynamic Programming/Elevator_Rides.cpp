#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<pii> dp(1 << n, {1e9, 1e9});
    dp[0] = {0, k};
    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                if (dp[mask ^ (1 << i)].se + v[i] > k){
                    dp[mask] = min(dp[mask], {dp[mask ^ (1 << i)].fi + 1, v[i]});
                } else {
                    dp[mask] = min(dp[mask], {dp[mask ^ (1 << i)].fi, dp[mask ^ (1 << i)].se + v[i]});
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].fi << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}