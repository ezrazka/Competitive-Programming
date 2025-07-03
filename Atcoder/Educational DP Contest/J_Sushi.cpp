#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> cnt(3);
    for (int i = 0; i < n; i++){
        int x; cin >> x; x--;
        cnt[x]++;
    }

    vector<int> mx_cnt(3);
    mx_cnt[2] = cnt[2];
    for (int i = 1; i >= 0; i--){
        mx_cnt[i] = mx_cnt[i + 1] + cnt[i];
    }

    vector<vector<vector<ld>>> dp(mx_cnt[0] + 1, vector<vector<ld>>(mx_cnt[1] + 1, vector<ld>(mx_cnt[2] + 1)));
    dp[0][0][0] = 0;
    for (int k = 0; k <= mx_cnt[2]; k++){
        for (int j = 0; j <= mx_cnt[1]; j++){
            for (int i = 0; i <= mx_cnt[0]; i++){
                if (i - 1 >= 0){
                    dp[i][j][k] += dp[i - 1][j][k] * i / (i + j + k);
                }
                if (j - 1 >= 0 && i + 1 <= mx_cnt[0]){
                    dp[i][j][k] += dp[i + 1][j - 1][k] * j / (i + j + k);
                }
                if (k - 1 >= 0 && j + 1 <= mx_cnt[1]){
                    dp[i][j][k] += dp[i][j + 1][k - 1] * k / (i + j + k);
                }
                if (i + j + k >= 1){
                    dp[i][j][k] += (ld) n / (i + j + k);
                }
            }
        }
    }
    cout << fixed << setprecision(10) << dp[cnt[0]][cnt[1]][cnt[2]] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}