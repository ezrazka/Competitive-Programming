#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int l, n, m; cin >> l >> n >> m;
    vector<int> a(l + 1);
    for (int i = 1; i <= l; i++){
        cin >> a[i];
    }
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> b[i][j];
        }
    }

    bool dp[n + 1][m + 1][l + 1];
    int suff[n + 2][m + 2][l + 1];
    memset(dp, true, sizeof(dp));
    memset(suff, 0, sizeof(suff));
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            for (int k = 1; k <= l; k++){
                if (b[i][j] == a[k]){
                    if (k == l) dp[i][j][l] = false;
                    else dp[i][j][k] = (suff[i + 1][j + 1][k + 1] < (n - i) * (m - j));
                }
                suff[i][j][k] = dp[i][j][k] + suff[i + 1][j][k] + suff[i][j + 1][k] - suff[i + 1][j + 1][k];
            }
        }
    }
    
    bool ok = false;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!dp[i][j][1]){
                ok = true;
                i = n + 1, j = m + 1;
            }
        }
    }
    cout << (ok ? "T\n" : "N\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}