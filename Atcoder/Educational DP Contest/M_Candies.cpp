#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    vector<vector<int>> pref(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    pref[0][0] = 1;
    for (int i = 1; i <= k; i++){
        pref[0][i] = pref[0][i - 1];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            if (j - v[i - 1] - 1 < 0){
                dp[i][j] = pref[i - 1][j];
            } else {
                dp[i][j] = ((pref[i - 1][j] - pref[i - 1][j - v[i - 1] - 1]) % MOD + MOD) % MOD;
            }
            if (j - 1 < 0){
                pref[i][j] = dp[i][j];
            } else {
                pref[i][j] = (pref[i][j - 1] + dp[i][j]) % MOD;
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