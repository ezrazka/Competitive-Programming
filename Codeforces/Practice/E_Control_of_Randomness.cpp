#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

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

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n);
    vector<vector<int>> dp(n, vector<int>(2));
    auto dfs = [&](auto self, int node, int parent) -> void {
        par[node] = parent;
        dp[node][0] = 1;
        dp[node][1] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                dp[node][0] = (dp[node][0] + (dp[child][1] + 1)) % MOD;
            }
        }
        /*
        dp[node] = 1 + sum(dp[children] + dp[node]) / (children + 1)
        dp[node] - dp[node] * children / (children + 1) = 1 + sum(dp[children]) / (children + 1)
        dp[node](1 - children / (children + 1)) = 1 + sum(dp[children]) / (children + 1)
        dp[node] = (children + 1) + sum(dp[children])
        */
    };
    dfs(dfs, 0, -1);
    dp[0][0] = 0;
    dp[0][1] = 0;

    while (q--){
        int v, p; cin >> v >> p; v--;
        int ans = 0;
        priority_queue<int> pq;
        int cur = v;
        int parity = 1;
        while (cur != 0){
            ans = (ans + dp[cur][parity]) % MOD;
            pq.push(dp[cur][parity]);
            cur = par[cur];
            parity ^= 1;
        }
        while (!pq.empty() && p--){
            ans = ((ans - (pq.top() - 1)) % MOD + MOD) % MOD;
            pq.pop();
        }
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}