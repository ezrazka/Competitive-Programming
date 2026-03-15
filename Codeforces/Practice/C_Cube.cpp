#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    int a[n + 1][n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                cin >> a[i][j][k];
            }
        }
    }

    int dp[1 << n][1 << n]; // dp[index][rows used][cols used]
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        vector<int> masks;
        for (int mask = 0; mask < (1 << n); mask++){
            if (__builtin_popcount(mask) == i){
                masks.push_back(mask);
            }
        }
        for (int mask1 : masks){
            for (int mask2 : masks){
                dp[mask1][mask2] = 1e9;
                for (int temp1 = mask1, bit1 = temp1 & -temp1; temp1 > 0; temp1 ^= temp1 & -temp1, bit1 = temp1 & -temp1){
                    for (int temp2 = mask2, bit2 = temp2 & -temp2; temp2 > 0; temp2 ^= temp2 & -temp2, bit2 = temp2 & -temp2){
                        dp[mask1][mask2] = min(dp[mask1][mask2], dp[mask1 ^ bit1][mask2 ^ bit2] + a[i][__lg(bit1) + 1][__lg(bit2) + 1]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][(1 << n) - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}