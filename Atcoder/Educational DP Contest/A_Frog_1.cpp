#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + abs(v[i] - v[i - 1]);
        if (i - 2 >= 0){
            dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 2]));
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