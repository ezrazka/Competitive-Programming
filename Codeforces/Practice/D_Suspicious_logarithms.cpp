#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int l, r; cin >> l >> r;

    auto pow = [&](int x, int exponent){ // returns x^exponent
        int res = 1;
        while (exponent > 0){
            if (exponent & 1) res *= x;
            x *= x;
            exponent >>= 1;
        }
        return res;
    };

    auto log = [&](int base, int x){ // returns log_{base}(x)
        int res = 0;
        while (x >= base){
            res++;
            x /= base;
        }
        return res;
    };

    auto range_log = [&](int base, int l, int r){ // returns the sum of log_{base}(i), for l <= i <= r
        int res = 0;
        while (r >= l){
            int log_base = log(base, r);
            int next_r = max(l, pow(base, log_base)) - 1;
            res += (log_base * (r - next_r)) % MOD;
            res %= MOD;
            r = next_r;
        }
        return res;
    };

    auto range_g = [&](int l, int r){ // returns the sum of g(i), for 1 <= i <= x
        int res = 0;
        while (r >= l){
            int log_2 = log(2, r);
            int next_r = max(l, pow(2, log_2)) - 1;
            res += range_log(log_2, next_r + 1, r);
            res %= MOD;
            r = next_r;
        }
        return res;
    };

    cout << (range_g(l, r) % MOD + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}