#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

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
    vector<int> c(4);
    cin >> c[0] >> c[1] >> c[2] >> c[3];

    if (c[0] + c[1] + c[2] + c[3] <= 1){
        cout << 1 << '\n';
        return;
    }

    if (abs(c[0] - c[1]) > 1){
        cout << 0 << '\n';
        return;
    }

    if (!c[0] && !c[1] && c[2] && c[3]){
        cout << 0 << '\n';
        return;
    }

    if (!c[0] && !c[1] && (c[2] || c[3])){
        cout << 1 << '\n';
        return;
    }

    if (c[0] < c[1]){
        int ans = 1;
        ans = (ans * C(c[2] + c[1] - 1, c[1] - 1)) % MOD;
        ans = (ans * C(c[3] + c[1] - 1, c[1] - 1)) % MOD;
        cout << ans << '\n';
    } else if (c[0] > c[1]){
        int ans = 1;
        ans = (ans * C(c[2] + c[0] - 1, c[0] - 1)) % MOD;
        ans = (ans * C(c[3] + c[0] - 1, c[0] - 1)) % MOD;
        cout << ans << '\n';
    } else {
        int ans1 = 1, ans2 = 1;
        ans1 = (ans1 * C(c[2] + c[1], c[1])) % MOD;
        ans1 = (ans1 * C(c[3] + c[1] - 1, c[1] - 1)) % MOD;
        ans2 = (ans2 * C(c[2] + c[1] - 1, c[1] - 1)) % MOD;
        ans2 = (ans2 * C(c[3] + c[1], c[1])) % MOD;
        cout << (ans1 + ans2) % MOD << '\n';
    }

}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}