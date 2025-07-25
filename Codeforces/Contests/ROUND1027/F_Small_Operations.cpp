#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> spf(1e6 + 1);

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1;
    spf[1] = -1;
    for (int i = 2; i * i <= 1e6; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= 1e6; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

map<int, int> get_prime_factorization(int x){
    map<int, int> res;
    while (x > 1){
        res[spf[x]]++;
        x /= spf[x];
    }
    return res;
}

vector<int> get_factors(int x){
    vector<int> res_small, res_big;
    for (int i = 1; i * i <= x; i++){
        if (x % i == 0){
            res_small.push_back(i);
            if (i != x / i){
                res_big.push_back(x / i);
            }
        }
    }
    reverse(res_big.begin(), res_big.end());
    for (int f : res_big){
        res_small.push_back(f);
    }
    return res_small;
}

int calc(int x, int k){
    int res = 0;
    vector<int> dp(x + 1, 1e18);
    dp[x] = 0;
    for (int i = x; i >= 2; i--){
        vector<int> factors = get_factors(i);
        for (int f : factors){
            
        }
    }
    return res;
}

void solve(){
    int a, b, k; cin >> a >> b >> k;
    map<int, int> pf_a = get_prime_factorization(a);
    map<int, int> pf_b = get_prime_factorization(b);
    for (auto [prime, freq] : pf_b){
        pf_a[prime];
    }

    int pos = 1, neg = 1;
    for (auto [prime, freq] : pf_a){
        int val = freq - pf_b[prime];
        if (val == 0) continue;
        if (val < 0){
            while (val++){
                neg *= prime;
            }
        } else {
            while (val--){
                pos *= prime;
            }
        }
    }

    int aa = calc(pos, k);
    int bb = calc(neg, k);
    if (aa == -1 || bb == -1){
        cout << -1 << '\n';
    } else {
        cout << aa + bb << '\n';
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