#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n), size(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        size[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                depth[child] = depth[node] + 1;
                self(self, child, node);
                size[node] += size[child];
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<int> depth_sum(n);
    depth_sum[0] = accumulate(depth.begin(), depth.end(), 0ll);
    auto dfs2 = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                depth_sum[child] = depth_sum[node] + (n - 2 * size[child]);
                self(self, child, node);
            }
        }
    };
    dfs2(dfs2, 0, -1);

    for (int node = 0; node < n; node++){
        cout << depth_sum[node] << " \n"[node == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}