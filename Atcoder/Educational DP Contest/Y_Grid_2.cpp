#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

vector<int> fact(2e5 + 1);
vector<int> inv_fact(2e5 + 1);

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
    return (P(n, r) * inv_fact[r]) % MOD;
}

int F(int x, int y){
    return C(x + y, x);
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 2e5; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[2e5] = inv(fact[2e5]);
    for (int i = 2e5 - 1; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++){
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
        return a < b;
    }); 

    vector<int> contribution(k);
    for (int i = 0; i < k; i++){
        contribution[i] = F(v[i].fi - 1, v[i].se - 1);
    }
    for (int i = 0; i < k; i++){
        for (int j = i + 1; j < k; j++){
            if (v[i].se > v[j].se) continue;
            contribution[j] -= (contribution[i] * F(v[j].fi - v[i].fi, v[j].se - v[i].se)) % MOD;
            contribution[j] = (contribution[j] % MOD + MOD) % MOD;
        }
    }

    int ans = F(n - 1, m - 1);
    for (int i = 0; i < k; i++){
        ans -= (contribution[i] * F(n - v[i].fi, m - v[i].se)) % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }
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