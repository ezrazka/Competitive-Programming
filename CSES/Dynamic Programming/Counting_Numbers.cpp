#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int calc(int x){
    if (x < 0) return 0;

    string s = to_string(x);
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(10));
    for (int i = 1; i <= n; i++){
        if (i == 1){
            for (int d = 0; d <= s[i - 1] - '0'; d++){
                dp[i][d] = 1;
            }
        } else {
            for (int pd = 0; pd < s[i - 2] - '0'; pd++){
                for (int d = 0; d <= 9; d++){
                    if (d == 0 || d != pd){
                        dp[i][d] += dp[i - 1][pd];
                    }
                }
            }
            int pd = s[i - 2] - '0';
            for (int d = 0; d <= s[i - 1] - '0'; d++){
                if (d == 0 || d != pd){
                    dp[i][d] += dp[i - 1][pd];
                }
            }
            if (x == 1 || x == 10){
                for (int i = 0; i <= 9; i++){
                    cout << dp[n][i] << '\n';
                }
            }
        }
    }
    if (x == 1 || x == 10){
        for (int i = 0; i <= 9; i++){
            cout << dp[n][i] << '\n';
        }
    }
    return accumulate(dp[n].begin(), dp[n].end(), 0ll);
}

void solve(){
    int a, b; cin >> a >> b;

    for (int i = 0; i <= 100; i++){
        cout << i << ": " << calc(i) << '\n';
    }

    cout << calc(b) << ' ' << calc(a - 1) << '\n';
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