#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> w(n), v(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    vector<int> dp(sum + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = sum; j - v[i] >= 0; j--){
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    for (int i = sum; i >= 0; i--){
        if (dp[i] <= k){
            cout << i << '\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}