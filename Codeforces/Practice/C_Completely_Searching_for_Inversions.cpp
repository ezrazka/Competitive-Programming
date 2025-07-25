#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int u = 0; u < n; u++){
        int m; cin >> m;
        for (int _ = 0; _ < m; _++){
            int v, w; cin >> v >> w; v--;
            adj[u].push_back({v, w});
        }
    }

    vector<int> cnt_0(n), cnt_1(n), inv(n);
    vector<bool> vis(n);
    auto dfs = [&](auto self, int node) -> void {
        vis[node] = true;
        for (auto [child, w] : adj[node]){
            if (!vis[child]){
                self(self, child);
            }
            if (w == 0){
                inv[node] = (inv[node] + cnt_1[node]) % MOD;
                cnt_0[node] = (cnt_0[node] + 1) % MOD;
            } else {
                cnt_1[node] = (cnt_1[node] + 1) % MOD;
            }
            inv[node] = (inv[node] + inv[child]) % MOD;
            inv[node] = (inv[node] + (cnt_0[child] * cnt_1[node]) % MOD) % MOD;
            cnt_0[node] = (cnt_0[node] + cnt_0[child]) % MOD;
            cnt_1[node] = (cnt_1[node] + cnt_1[child]) % MOD;
        }
    };
    dfs(dfs, 0);

    cout << inv[0] << '\n';

    /*
    for each x, each dfs(x) always appends the same sequence of Ws
    store cnt_0, cnt_1, inv
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}