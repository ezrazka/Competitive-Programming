#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; v++){
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }

    vector<int> depth(n);
    auto dfs = [&](auto self, int node) -> void {
        depth[node] = 1;
        for (int child : adj[node]){
            self(self, child);
            depth[node] = max(depth[node], depth[child] + 1);
        }
    };
    dfs(dfs, 0);

    int ub = accumulate(depth.begin(), depth.end(), 0ll) - n;
    cout << (k <= ub ? "YA\n" : "TIDAK\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}