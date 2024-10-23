#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

vector<int> fact(1001), inv_fact(1001);

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

int C(int n, int r){
    return ((fact[n] * inv_fact[n - r]) % MOD * inv_fact[r]) % MOD;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[1000] = inv(fact[1000]);
    for (int i = 999; i >= 0; i--){
        inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int n, a, b; cin >> n >> a >> b;

    int ans = 0;
    for (int i = a; i <= b; i++){
        ans += C(n, i);
        ans %= MOD;
    }
    cout << ans << '\n';
}