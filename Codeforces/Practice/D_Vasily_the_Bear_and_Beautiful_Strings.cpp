#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;
constexpr int M = 2e5;

vector<int> fact(M + 1);
vector<int> inv_fact(M + 1);

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
    if (n < 0 || r < 0) return 0;
    return (fact[n] * inv_fact[n - r]) % MOD;
}

int C(int n, int r){
    if (n < 0 || r < 0) return 0;
    return (P(n, r) * inv_fact[r]) % MOD;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= M; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[M] = inv(fact[M]);
    for (int i = M - 1; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

int dp0(int, int);
int dp1(int, int);

int dp0(int zeros, int ones){
    if (zeros < 0 || ones < 0 || zeros == 0 && ones == 0) return 0;
    if (zeros == 1 && ones == 0) return 1;
    // return (dp0(zeros, ones - 1) + dp1(zeros, ones - 1) + dp1(zeros - 1, ones)) % MOD; // naive
    return (C(zeros + ones - 1, ones - 1) + dp1(zeros - 1, ones)) % MOD; // optimized
}

int dp1(int zeros, int ones){
    if (zeros < 0 || ones < 0 || zeros == 0 && ones == 0) return 0;
    if (zeros == 0 && ones == 1) return 1;
    // return dp0(zeros - 1, ones); // naive
    return ((C(zeros + ones, zeros) - dp0(zeros, ones)) % MOD + MOD) % MOD; // optimized
}

void solve(){
    int n, m, g; cin >> n >> m >> g;
    if (n == 0 && m == 1 && g == 0) cout << 0 << '\n';
    else cout << (g == 0 ? dp0(n, m) : dp1(n, m)) << '\n';

    /*
    we can calculate g == 1 as the complement of g == 0

    we calculate dp(n, m) with g == 0,
    if it starts with 1: C(n + m - 1, m - 1)
    if it starts with 0: next we solving dp(n - 1, m) with g == 1 calculated through complement
    */
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