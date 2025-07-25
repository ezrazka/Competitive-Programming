#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    vector<int> sums(1 << n);
    for (int mask = 0; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if ((mask & (1 << i)) && (mask & (1 << j))){
                    sums[mask] += v[i][j];
                }
            }
        }
    }

    vector<int> dp(1 << n);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++){
        dp[mask] = sums[mask];
        for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask){
            dp[mask] = max(dp[mask], dp[submask] + dp[mask ^ submask]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}