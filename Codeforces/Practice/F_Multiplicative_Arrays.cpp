#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
const int N = 1e5;
const int M = 40;

vector<int> spf(N + 1);
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
    if (n > M){
        int res = 1;
        for (int i = n; i > n - r; i--){
            res = (res * i) % MOD;
        }
        return res;
    }
    return (fact[n] * inv_fact[n - r]) % MOD;
}

int C(int n, int r){
    if (n > M){
        int res = P(n, r);
        for (int i = 1; i <= r; i++){
            res = (res * inv(i)) % MOD;
        }
        return res;
    }
    return (P(n, r) * inv_fact[r]) % MOD;
}

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1, spf[1] = -1;
    for (int i = 2; i * i <= N; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= N; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    fact[0] = 1;
    for (int i = 1; i <= M; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[M] = inv(fact[M]);
    for (int i = M - 1; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve(){
    int k, n; cin >> k >> n;
    
    vector<int> hockey_stick(M / 2 + 1);
    hockey_stick[0] = n + 1;
    for (int i = 1; i <= M / 2; i++){
        hockey_stick[i] = (hockey_stick[i - 1] * (((n - i + 1) * inv(i + 1)) % MOD)) % MOD;
    }

    for (int c = 1; c <= k; c++){
        if (c == 1){
            cout << n << " \n"[c == k];
            continue;
        }

        vector<int> freqs;
        int total_freq = 0;
        {
            int temp = c;
            while (temp > 1){
                int freq = 0;
                int prime = spf[temp];
                while (temp % prime == 0){
                    freq++;
                    temp /= prime;
                }
                freqs.push_back(freq);
                total_freq += freq;
            }
        }
        vector<int> cur(min(n, total_freq) + 1);
        int ans = 0;
        for (int i = 1; i <= min(n, total_freq); i++){
            cur[i] = 1;
            for (int j : freqs){
                cur[i] = (cur[i] * C(j + i - 1, i - 1)) % MOD;
            }
            for (int j = 1; j <= i - 1; j++){
                cur[i] = (cur[i] - (cur[j] * C(i, j)) % MOD) % MOD;
            }
            ans = (ans + (cur[i] * hockey_stick[i]) % MOD) % MOD;
        }
        cout << ((ans % MOD) + MOD) % MOD << " \n"[c == k];
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