#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> dp(1e6 + 1, vector<int>(20));
    for (int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        dp[r][0] = max(dp[r][0], l);
    }

    for (int i = 2; i <= 1e6; i++){
        dp[i] = max(dp[i], dp[i - 1]);
    }

    for (int bit = 1; bit < 20; bit++){
        for (int i = 0; i < n; i++){
            dp[i][bit] = dp[dp[i][bit - 1]][bit - 1];
        }
    }

    while (q--){
        int l, r; cin >> l >> r;
        
        int ans = 0;
        while (r > 0){
            int msb = -1;
            for (int bit = 19; bit >= 0; bit--){
                if (dp[r][bit] >= l){
                    msb = bit;
                    break;
                }
            }
            if (msb == -1) break;
            ans += (1 << msb);
            r = dp[r][msb];
        }
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}