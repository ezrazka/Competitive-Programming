#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int MOD = 1e9 + 9;

vector<int> fact(8000 + 1);
vector<int> inv_fact(8000 + 1);

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int P(int n, int r) {
    return (fact[n] * inv_fact[n - r]) % MOD;
}

int C(int n, int r) {
    return (P(n, r) * inv_fact[r]) % MOD;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 8000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[8000] = inv(fact[8000]);
    for (int i = 8000 - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve() {
    int n, w, b; cin >> n >> w >> b;

    int ans = 0;
    for (int l = 1; l <= n - 2; l++) {
        for (int r = 1; r <= n - l - 1; r++) {
            int m = n - l - r;
            if (l + r > w || m > b) continue;
            int ways = (C(b - 1, m - 1) * C(w - 1, l + r - 1)) % MOD;
            ans = (ans + ways) % MOD;
        }
    }
    ans = (ans * ((fact[w] * fact[b]) % MOD)) % MOD;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
