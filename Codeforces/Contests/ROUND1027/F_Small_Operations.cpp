#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<vector<int>> factors(1e6 + 1);

void init(){
    for (int i = 1; i <= 1e6; i++){
        for (int j = i; j <= 1e6; j += i){
            factors[j].push_back(i);
        }
    }
}

void solve(){
    int a, b, k; cin >> a >> b >> k;
    int gcd = __gcd(a, b);
    a /= gcd, b /= gcd;

    int mx = max(a, b);
    vector<int> memo(mx + 1, 1e18);
    auto calc = [&](auto self, int x) -> int {
        if (x == 1) return 0;
        if (memo[x] != 1e18) return memo[x];
        for (int f : factors[x]){
            if (f == 1) continue;
            if (f > k) break;
            if (self(self, x / f) != 1e18){
                memo[x] = min(memo[x], self(self, x / f) + 1);
            }
        }
        return memo[x];
    };

    int res_a = calc(calc, a);
    int res_b = calc(calc, b);
    if (res_a == 1e18 || res_b == 1e18){
        cout << -1 << '\n';
    } else {
        cout << res_a + res_b << '\n';
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