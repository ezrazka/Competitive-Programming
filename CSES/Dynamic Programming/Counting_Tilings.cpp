#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> dp(m + 1, vector<int>(1 << n));
    dp[0][(1 << n) - 1] = 1;
    for (int i = 1; i <= m; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            for (int subset = mask; subset >= 0; subset = (subset - 1) & mask){
                int prev_mask = subset | (mask ^ ((1 << n) - 1));
                
                bool ok = true;
                int cnt = 0;
                for (int j = 0; j < n; j++){
                    if (mask & prev_mask & (1 << j)){
                        cnt++;
                    } else {
                        if (cnt & 1) ok = false;
                        cnt = 0;
                    }
                }
                if (cnt & 1) ok = false;
                cnt = 0;

                if (ok){
                    dp[i][mask] += dp[i - 1][prev_mask];
                    dp[i][mask] %= MOD;
                }
                if (subset == 0) break;
            }
        }
    }

    cout << dp[m][(1 << n) - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}