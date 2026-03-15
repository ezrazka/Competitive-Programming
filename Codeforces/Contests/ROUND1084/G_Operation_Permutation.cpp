#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;
const int N = 3e3;
vector<int> fact(N + 1);
vector<int> inv_fact(N + 1);

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
    return (fact[n] * inv(fact[n - r])) % MOD;
}

int C(int n, int r){
    return (P(n, r) * inv(fact[r])) % MOD;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= N; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve(){
    int n, x; cin >> n >> x;
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        if (a[i].first == '-') a[i] = {'+', (-a[i].second + MOD) % MOD};
        if (a[i].first == '/') a[i] = {'x', inv(a[i].second)};
    }

    vector<int> sums, products;
    for (int i = 0; i < n; i++){
        if (a[i].first == '+') sums.push_back(a[i].second);
        else products.push_back(a[i].second);
    }
    int ns = sums.size();
    int np = products.size();

    vector<int> dp(np + 1);
    dp[0] = 1;
    for (int i = 0; i < np; i++){
        for (int j = np; j >= 1; j--){
            dp[j] += (products[i] * dp[j - 1]) % MOD; dp[j] %= MOD;
        }
    }

    int ans = (x * dp[np]) % MOD;
    if (ns > 0){
        int sums_avg = 0;
        for (int i = 0; i < ns; i++){
            sums_avg += sums[i]; sums_avg %= MOD;
        }
        sums_avg *= inv(ns);
        sums_avg %= MOD;

        for (int i = 0; i < ns; i++){
            int cur = 0;
            for (int j = 0; j <= np; j++){
                int ways = (C(i + (np - j), np - j) * C(((ns - 1) - i) + j, j)) % MOD;
                int value = (dp[j] * inv(C(np, j))) % MOD;
                cur += (ways * value) % MOD; cur %= MOD;
            }
            cur *= inv(C(n, np)); cur %= MOD;
            cur *= sums_avg; cur %= MOD;
            ans += cur; ans %= MOD;
        }
    }
    cout << ans << '\n';
    
    /*
    we can assume + and - are identical operations
    as well as x and /
    only addition and subtraction: evaluate normally
    only multiplication and division: evaluate normally
    all four: ??

    E[x + y] = E[x] + E[y]

    let any addition/subtraction be 0
    and any multiplication/division be 1
    then we must calculate all permutations of the binary string

    we can calculate the contribution of each index using stars and bars
    for each index we fix the number of numbers its multiplied by
    */
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