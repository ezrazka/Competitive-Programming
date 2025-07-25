#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    vector<int> dp(1 << n);
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        vector<int> next = dp;
        for (int mask = 0; mask < (1 << n); mask++){
            if (__builtin_popcount(mask) != i + 1) continue;
            for (int j = 0; j < n; j++){
                if (!(mask & (1 << j))) continue;
                if (!adj[i][j]) continue;
                next[mask] += dp[mask ^ (1 << j)];
                next[mask] %= MOD;
            }
        }
        dp = next;
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