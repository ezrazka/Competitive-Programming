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

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + v[i - 1];
    }

    vector<vector<int>> dp(n, vector<int>(n, 1e18));
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (i == j){
                dp[i][j] = 0;
            } else {
                for (int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (pref[k + 1] - pref[i]) + (pref[j + 1] - pref[k + 1]));
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}