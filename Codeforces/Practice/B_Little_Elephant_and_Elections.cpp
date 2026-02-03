#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;

void solve(){
    int m; cin >> m;

    string s = to_string(m);
    int n = s.length();

    int dp[n + 1][10][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 10; j++){
            for (int digit = 0; digit < 10; digit++){
                bool is_lucky = (digit == 4) || (digit == 7);

                auto update = [&](int x, int y){
                    if (j - is_lucky >= 0){
                        dp[i][j][x] += dp[i - 1][j - is_lucky][y];
                    }
                };
                
                update(0, 0);
                if (digit < s[i - 1] - '0'){
                    update(0, 1);
                } else if (digit == s[i - 1] - '0'){
                    update(1, 1);
                }
            }
        }
    }
    dp[n][0][0]--;

    int ans = 0;
    vector<int> freq(10);
    for (int i = 1; i <= min(9ll, n); i++){
        for (int j = 0; j < 1'000'000; j++){
            int sum = 0;
            {
                int temp = j;
                for (int k = 0; k < 6; k++){
                    freq[temp % 10]++;
                    sum += temp % 10;
                    temp /= 10;
                }
            }
            if (sum < i){
                int prod = dp[n][i][0] + dp[n][i][1];
                for (int k = 0; k < 10; k++){
                    for (int l = 0; l < freq[k]; l++){
                        prod *= (dp[n][k][0] + dp[n][k][1]) - l;
                        prod %= MOD;
                    }
                }
                ans += prod;
                ans %= MOD;
            }
            {
                int temp = j;
                for (int k = 0; k < 6; k++){
                    freq[temp % 10]--;
                    temp /= 10;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}