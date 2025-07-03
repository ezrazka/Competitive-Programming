#include <bits/stdc++.h>
using namespace std;

#define int long long
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

    vector<int> dp(n, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = max(0ll, i - k); j < i; j++){
            dp[i] = min(dp[i], dp[j] + abs(v[i] - v[j]));
        }
    }
    cout << dp[n - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}