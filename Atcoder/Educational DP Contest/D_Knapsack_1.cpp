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
    for (int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - w[i - 1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << dp[n][k] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}