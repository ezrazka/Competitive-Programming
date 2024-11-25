#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

vector<int> fact(1e6 + 1);

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 1e6; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve(){
    int n, m; cin >> n >> m;

    if (m == 1){
        if (n == 1){
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(2)); // 1: WLOG color 1, 0: WLOG colors 2 to m
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i][0] = ((dp[i - 1][0] * (m - 2)) % MOD + (dp[i - 1][1] * (m - 1)) % MOD) % MOD;
        dp[i][1] = dp[i - 1][0];
    }
    cout << (dp[n][0] * fact[m]) % MOD << '\n';
    // rotatability
    // if dp[1] is color 1, probability dp[n] is not color 1
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}