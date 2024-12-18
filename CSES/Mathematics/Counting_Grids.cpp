#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

vector<int> fact(2e6 + 1);
vector<int> inv_fact(2e6 + 1);

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

int P(int n, int r){
    return (fact[n] * inv_fact[n - r]) % MOD;
}

int C(int n, int r){
    if (r < 0) return 0;
    return (P(n, r) * inv_fact[r]) % MOD;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 2e6; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[2e6] = inv(fact[2e6]);
    for (int i = 2e6 - 1; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve(){
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < 4; i++){
        ans += binpow(2, (n & 1) + (n * n / 4) % (MOD - 1) * __gcd(i, 4ll) % (MOD - 1));
        ans %= MOD;
    }
    ans = (ans * inv(4)) % MOD;

    cout << ans << '\n';
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