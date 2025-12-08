#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

vector<int> fact(1e5 + 1);
vector<int> inv_fact(1e5 + 1);

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
    for (int i = 1; i <= 1e5; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[1e5] = inv(fact[1e5]);
    for (int i = 1e5 - 1; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n), index(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        index[v[i]] = i;
    }

    set<int> ex;
    for (int i = 0; i <= n; i++){
        ex.insert(i);
    }

    int ans = 1;
    int l = index[0], r = index[0];
    ex.erase(0);
    while (r - l + 1 < n){
        int old_mex = *ex.begin();
        l = min(l, index[old_mex]);
        r = max(r, index[old_mex]);
        {
            while (true){
                int mex = *ex.begin();
                if (mex < n && l <= index[mex] && index[mex] <= r){
                    ex.erase(mex);
                } else break;
            }
        }
        int new_mex = *ex.begin();
        int free_spaces = (r - l + 1) - old_mex - 1;
        int to_fix = new_mex - old_mex - 1;
        ans *= P(free_spaces, to_fix);
        ans %= MOD;
    }
    cout << ans << '\n';
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