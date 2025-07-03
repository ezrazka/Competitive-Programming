#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == 1 && j == 1){
                dp[i][j] = 1;
                continue;
            }
            if (v[i - 1][j - 1] == '#'){
                continue;
            }
            if (i - 2 >= 0 && v[i - 2][j - 1] != '#'){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j - 2 >= 0 && v[i - 1][j - 2] != '#'){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][m] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}