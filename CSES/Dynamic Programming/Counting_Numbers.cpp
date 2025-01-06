#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int calc(int x){
    if (x == -1) return 0;

    string s = "0" + to_string(x);
    int n = s.length() - 1;

    int dp[n + 1][10][2][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int d = 0; d < 10; d++){
            for (int pd = 0; pd < 10; pd++){
                if (d == pd){
                    if (d == 0){
                        dp[i][d][1][0] += dp[i - 1][pd][1][0];
                        if (d < s[i] - '0'){
                            dp[i][d][1][0] += dp[i - 1][pd][1][1];
                        }
                        if (d == s[i] - '0'){
                            dp[i][d][1][1] += dp[i - 1][pd][1][1];
                        }
                    }
                    continue;
                }
                dp[i][d][0][0] += dp[i - 1][pd][0][0];
                dp[i][d][0][0] += dp[i - 1][pd][1][0];
                if (d < s[i] - '0'){
                    dp[i][d][0][0] += dp[i - 1][pd][0][1];
                    dp[i][d][0][0] += dp[i - 1][pd][1][1];
                }
                if (d == s[i] - '0'){
                    dp[i][d][0][1] += dp[i - 1][pd][0][1];
                    dp[i][d][0][1] += dp[i - 1][pd][1][1];
                }
            }
        }
    }

    int res = 0;
    for (int d = 0; d < 10; d++){
        for (int leading : {0, 1}){
            for (int tight : {0, 1}){
                res += dp[n][d][leading][tight];
            }
        }
    }

    return res;
}

void solve(){
    int a, b; cin >> a >> b;

    cout << calc(b) - calc(a - 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}