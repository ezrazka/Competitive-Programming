#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
const int N = 20;

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
    return (fact[n] * inv_fact[n - r]) % MOD;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= N; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[N] = inv(fact[N]);
    for (int i = N - 1; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++){
        vector<int> activate(n + 1);
        for (int i = 0; i < n; i++){
            activate[a[i][j] - 1]++;
        }
        vector<int> dp(n + 2);
        dp[n + 1] = 1;
        int available = 0;
        for (int i = n; i >= 1; i--){
            available += activate[i];
            dp[i] = (dp[i + 1] * available) % MOD;
            available = max(0ll, available - 1);
        }
        ans = (ans + (1 - dp[1] * inv_fact[n]) % MOD) % MOD;
    }
    cout << (ans + MOD) % MOD << '\n';
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