#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
const int N = 2e5 + 1;

vector<int> spf(N + 1);

int binpow(int a, int b){
    int res = 1;
    while  (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
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
}

void solve(){
    int n; cin >> n;
    vector<vector<pair<int, pair<int, int>>>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        int p, q; cin >> p >> q;
        {
            int gcd = __gcd(p, q);
            p /= gcd, q /= gcd;
        }
        adj[u].emplace_back(v, pair<int, int>{p, q});
        adj[v].emplace_back(u, pair<int, int>{q, p});
    }
    
    vector<int> dp(n);
    map<int, int> lcm;
    map<int, int> mp;
    int ans = 0;
    auto dfs = [&](auto self, int node, int parent) -> void {
        ans = (ans + dp[node]) % MOD;
        for (auto [child, factor] : adj[node]){
            auto [p, q] = factor;
            if (child != parent){
                int val = (q * inv(p)) % MOD;
                dp[child] = (dp[node] * val) % MOD;
                {
                   int temp = q;
                    while (temp > 1){
                        int prime = spf[temp];
                        int cnt = 0;
                        while (temp % prime == 0){
                            cnt++;
                            temp /= prime;
                        }
                        mp[prime] -= cnt;
                    }
                }
                {
                    int temp = p;
                    while (temp > 1){
                        int prime = spf[temp];
                        int cnt = 0;
                        while (temp % prime == 0){
                            cnt++;
                            temp /= prime;
                        }
                        mp[prime] += cnt;
                        lcm[prime] = max(lcm[prime], mp[prime]);
                    }
                }
                self(self, child, node);
                {
                   int temp = q;
                    while (temp > 1){
                        int prime = spf[temp];
                        int cnt = 0;
                        while (temp % prime == 0){
                            cnt++;
                            temp /= prime;
                        }
                        mp[prime] += cnt;
                    }
                }
                {
                    int temp = p;
                    while (temp > 1){
                        int prime = spf[temp];
                        int cnt = 0;
                        while (temp % prime == 0){
                            cnt++;
                            temp /= prime;
                        }
                        mp[prime] -= cnt;
                    }
                }
            }
        }
    };
    dp[0] = 1;
    dfs(dfs, 0, -1);
    
    for (auto [prime, cnt] : lcm){
        while (cnt--){
            ans = (ans * prime) % MOD;
        }
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