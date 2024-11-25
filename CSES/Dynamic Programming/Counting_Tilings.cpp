#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void add(int& a, int b){
    a = (a + b) % MOD;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<int> dp(1 << n), prev(1 << n);
    prev[(1 << n) - 1] = 1;
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            for (int mask = 0; mask < (1 << n); mask++){
                dp[mask] = prev[mask ^ (1 << i)];
                if (i >= 1 && (mask & (1 << i)) && (mask & (1 << i - 1))){
                    add(dp[mask], prev[mask ^ (1 << i - 1)]);
                }
            }
            for (int mask = 0; mask < (1 << n); mask++){
                prev[mask] = dp[mask];
            }
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