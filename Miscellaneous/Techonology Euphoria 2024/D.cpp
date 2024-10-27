#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int k, n; cin >> k >> n;
    vector<int> v(n);
    v[0] = 1;
    for (int i = 1; i < n; i++){
        cin >> v[i];
    }
    
    vector<int> dp(k + 1, 1e18);
    dp[0] = 0;
    for (int j = 0; j < n; j++){
        for (int i = v[j]; i <= k; i++){
            dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
    }
    cout << dp[k] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}