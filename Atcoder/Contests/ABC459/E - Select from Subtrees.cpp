#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

const int MOD = 998244353;

vector<int> inv_fact(1e6 + 1);

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

int C(int n, int r) {
    int res = inv_fact[r];
    for (int i = n; i > n - r; i--) {
        res = (res * i) % MOD;
    }
    return res;
}

void init() {
    int fact_n = 1;
    for (int i = 1; i <= 1e6; i++) {
        fact_n = (fact_n * i) % MOD;
    }
    inv_fact[1e6] = inv(fact_n);
    for (int i = 1e6 - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; v++) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<int> sum_c(n), sum_d(n);
    {
        auto dfs = [&](auto self, int node) -> void {
            sum_c[node] = c[node];
            sum_d[node] = d[node];
            for (int child : adj[node]) {
                self(self, child);
                sum_c[node] = sum_c[node] + sum_c[child];
                sum_d[node] = sum_d[node] + sum_d[child];
            }
        };
        dfs(dfs, 0);
    }

    for (int node = 0; node < n; node++) {
        if (sum_d[node] > sum_c[node]) {
            cout << 0 << '\n';
            return;
        }
    }

    vector<int> dp(n);
    {
        auto dfs = [&](auto self, int node) -> void {
            dp[node] = C(sum_c[node] - sum_d[node] + d[node], d[node]);
            for (int child : adj[node]) {
                self(self, child);
                dp[node] = (dp[node] * dp[child]) % MOD;
            }
        };
        dfs(dfs, 0);
    }
    cout << dp[0] << '\n';
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
