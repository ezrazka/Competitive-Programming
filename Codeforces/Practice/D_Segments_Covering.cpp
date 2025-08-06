#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
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
    int n, m; cin >> n >> m;
    vector<int> l(n), r(n), p(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> l[i] >> r[i] >> a >> b;
        p[i] = (a * inv(b)) % MOD;
    }

    vector<vector<pair<int, int>>> ops(m + 1);
    for (int i = 0; i < n; i++){
        ops[r[i]].push_back({l[i], p[i]});
    }

    int complement_product = 1;
    for (int i = 0; i < n; i++){
        complement_product = (complement_product * (1 - p[i])) % MOD;
    }
    
    vector<int> dp(m + 1);
    dp[0] = complement_product;
    for (int r = 1; r <= m; r++){
        for (auto [l, p] : ops[r]){
            dp[r] = (dp[r] + ((dp[l - 1] * inv(1 - p)) % MOD * p) % MOD) % MOD;
        }
    }

    cout << (dp[m] + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}