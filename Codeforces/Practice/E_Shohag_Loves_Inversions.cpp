#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n; cin >> n;

    vector<int> dp(n + 1);
    int sum = 0;
    for (int i = n; i >= 1; i--){
        dp[i] = (i * sum + 1) % MOD;
        sum = (sum + dp[i]) % MOD;
    }

    int ans = n - 1;
    for (int i = 3; i <= n; i++){
        int ways = ((i - 1) * (i - 2) / 2 - 1) % MOD;
        ans = (ans + ways * dp[i]) % MOD;
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}