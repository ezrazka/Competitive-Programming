#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, c; cin >> n >> m >> c;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    int dp[n][m][m];
    int mn[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mn[i][j] = 1e18;
            for (int k = 0; k < m; k++){
                if (i == 0){
                    if (j == 0){
                        dp[i][j][k] = c * k + v[i][(j + k) % m];
                    } else {
                        dp[i][j][k] = dp[i][j - 1][k] + v[i][(j + k) % m];
                    }
                } else {
                    if (j == 0){
                        dp[i][j][k] = mn[i - 1][j] + c * k + v[i][(j + k) % m];
                    } else {
                        dp[i][j][k] = min(dp[i][j - 1][k], mn[i - 1][j] + c * k) + v[i][(j + k) % m];
                    }
                }
                mn[i][j] = min(mn[i][j], dp[i][j][k]);
            }
        }
    }
    cout << mn[n - 1][m - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}