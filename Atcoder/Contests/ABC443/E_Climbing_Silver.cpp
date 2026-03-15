#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, c; cin >> n >> c;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> last(n + 1, vector<int>(n + 1, -1));
    for (int i = n - 1; i >= 1; i--){
        for (int j = 1; j <= n; j++){
            if (a[i + 1][j] == '#'){
                last[i][j] = i + 1;
            } else {
                last[i][j] = last[i + 1][j];
            }
        }
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
    dp[n][c] = true;
    for (int i = n - 1; i >= 1; i--){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == '.' || last[i][j] == -1){
                for (int k : {j - 1, j, j + 1}){
                    if (1 <= k && k <= n && dp[i + 1][k]){
                        dp[i][j] = true;
                    }
                }
            } else {
                dp[i][j] = dp[last[i][j]][j];
            }
        }
    }

    for (int j = 1; j <= n; j++){
        cout << dp[1][j];
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}