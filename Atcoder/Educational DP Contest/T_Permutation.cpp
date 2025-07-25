#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> pref(n, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++){
        pref[0][j] = (pref[0][j - 1] + dp[0][j - 1]) % MOD;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= i; j++){
            if (s[i - 1] == '>'){
                dp[i][j] = pref[i - 1][j];
            } else {
                dp[i][j] = ((pref[i - 1][i + 1] - pref[i - 1][j]) % MOD + MOD) % MOD;
            }
        }
        for (int j = 1; j <= n; j++){
            pref[i][j] = (pref[i][j - 1] + dp[i][j - 1]) % MOD;
        }
    }
    cout << pref[n - 1][n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}