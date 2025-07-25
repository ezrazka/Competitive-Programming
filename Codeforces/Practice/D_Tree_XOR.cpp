#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(20));
    vector<int> sz(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        sz[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                sz[node] += sz[child];
            }
        }
        for (int child : adj[node]){
            if (child != parent){
                for (int bit = 0; bit < 20; bit++){
                    dp[node][bit] += dp[child][bit];
                    if ((v[node] ^ v[child]) & (1 << bit)){
                        dp[node][bit] += sz[child];
                    }
                }
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<vector<int>> reroot(n, vector<int>(20));
    auto dfs_reroot = [&](auto self, int node, int parent, vector<int> dp_parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                vector<int> next_dp_parent = dp[node];
                for (int bit = 0; bit < 20; bit++){
                    next_dp_parent[bit] += dp_parent[bit];
                    if (parent != -1 && (v[node] ^ v[parent]) & (1 << bit)){
                        next_dp_parent[bit] += n - sz[node];
                    }
                    next_dp_parent[bit] -= dp[child][bit];
                    if ((v[node] ^ v[child]) & (1 << bit)){
                        next_dp_parent[bit] -= sz[child];
                    }
                }
                self(self, child, node, next_dp_parent);
            }
        }
        for (int bit = 0; bit < 20; bit++){
            reroot[node][bit] += dp_parent[bit];
            if (parent != -1 && (v[node] ^ v[parent]) & (1 << bit)){
                reroot[node][bit] += n - sz[node];
            }
        }
        for (int child : adj[node]){
            if (child != parent){
                for (int bit = 0; bit < 20; bit++){
                    reroot[node][bit] += dp[child][bit];
                    if ((v[node] ^ v[child]) & (1 << bit)){
                        reroot[node][bit] += sz[child];
                    }
                }
            }
        }
    };
    dfs_reroot(dfs_reroot, 0, -1, vector<int>(20));

    for (int node = 0; node < n; node++){
        int ans = 0;
        for (int bit = 0; bit < 20; bit++){
            ans += reroot[node][bit] * (1 << bit);
        }
        cout << ans << " \n"[node == n - 1];
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