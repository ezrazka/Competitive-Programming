#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
const int N = 1e6;

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
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++){
        cin >> v[i];
    }
    int sum = accumulate(v.begin(), v.end(), 0ll);

    int x = sum / n;

    for (int i = 1; i <= n; i++){
        if (v[i] > x + 1){
            cout << 0 << '\n';
            return;
        }
    }
    
    int remaining = v[0];
    for (int i = 1; i <= n; i++){
        remaining -= max(0ll, x - v[i]);
    }
    if (remaining < 0){
        cout << 0 << '\n';
        return;
    }

    int a = n - sum % n;
    int b = sum % n;
    int c = C(a + remaining, remaining);
    cout << ((c * fact[a]) % MOD * fact[b]) % MOD << '\n';

    /*
    if there were no 0,
    its solvable as long as the max difference between two elements is 1,
    lets assume there are A amount valued X and B amount valued X + 1
    the answer is then A! * B!

    we can distribute 0 to 1..n optimally and act as if the 0 doesnt exist
    we must count how many ways there are to have only values X and X + 1. call this C
    then the answer is A! * B! * C
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