#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
}

void solve(){
    int n; cin >> n;
    int inv_100 = inv(100);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        p[i] = (p[i] * inv(100)) % MOD;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = ((dp[i - 1] + 1) * inv(p[i])) % MOD;
    }
    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}