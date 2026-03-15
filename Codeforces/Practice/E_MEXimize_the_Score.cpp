#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
const int N = 2e5;

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

int C(int n, int r){
    return (P(n, r) * inv_fact[r]) % MOD;
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
    int n; cin >> n;
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> suff(n + 1);
    suff[n] = 1;
    for (int i = n - 1; i >= 0; i--){
        suff[i] = suff[i + 1];
        for (int _ = 0; _ < freq[i]; _++){
            suff[i] = (suff[i] * 2) % MOD;
        }
    }

    int ans = 0;
    vector<int> ways(n + 2, 1); // ways[j] = number of ways where freq[0..i-1] all >= j
    for (int i = 0; i < n; i++){
        int limit = ways.size() - 2;
        int next_limit = min(limit, freq[i]);

        vector<int> cur_ways(freq[i] + 2);
        cur_ways[freq[i]] = 1;
        for (int j = freq[i] - 1; j >= 0; j--){
            cur_ways[j] = (cur_ways[j + 1] + C(freq[i], j)) % MOD;
        }
        
        for (int j = 0; j <= next_limit; j++){
            int bottlenecks = ((ways[j] * (cur_ways[j] - cur_ways[j + 1])) % MOD * suff[i + 1]) % MOD;
            int non_bottlenecks = (((ways[j] - ways[j + 1]) * cur_ways[j + 1]) % MOD * suff[i + 1]) % MOD;
            ans = (ans + (j * (bottlenecks + non_bottlenecks)) % MOD) % MOD;
        }
        
        vector<int> next_ways(next_limit + 2);
        for (int j = 0, way_sum = 0; j <= next_limit + 1; j++){
            next_ways[j] = (ways[j] * cur_ways[j]) % MOD;
        }
        swap(ways, next_ways);
    }
    cout << (ans + MOD) % MOD << '\n';
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