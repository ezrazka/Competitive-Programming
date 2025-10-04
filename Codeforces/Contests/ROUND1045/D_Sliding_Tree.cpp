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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> depth(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                depth[node] = max(depth[node], depth[child] + 1);
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<int> dp(n);
    auto reroot = [&](auto self, int node, int parent, int depth_parent) -> void {
        dp[node] = max(depth[node], depth_parent + 1);

        int argmax = -1, argmax2 = -1;
        for (int child : adj[node]){
            if (child != parent){
                if (argmax == -1 || depth[child] > depth[argmax]){
                    argmax2 = argmax;
                    argmax = child;
                } else if (argmax2 == -1 || depth[child] > depth[argmax2]){
                    argmax2 = child;
                }
            }
        }

        for (int child : adj[node]){
            if (child != parent){
                if (child == argmax){
                    if (argmax2 == -1){
                        self(self, child, node, depth_parent + 1);
                    } else {
                        self(self, child, node, max(depth_parent, depth[argmax2]) + 1);
                    }
                } else {
                    self(self, child, node, max(depth_parent, depth[argmax]) + 1);
                }
            }
        }
    };
    reroot(reroot, 0, -1, -1);

    int best = -1;
    for (int node = 0; node < n; node++){
        if (adj[node].size() > 2){
            if (best == -1 || dp[node] > dp[best]){
                best = node;
            }
        }
    }

    if (best == -1){
        cout << -1 << '\n';
        return;
    }
    
    auto dfs_bad = [&](auto self, int node, int parent, int depth) -> int {
        if (depth == dp[best]){ return -2; }
        for (int child : adj[node]){
            if (child != parent){
                if (self(self, child, node, depth + 1) == -2){
                    if (node == best){
                        return child;
                    } else {
                        return -2;
                    }
                }
            }
        }
        return -1;
    };
    int bad_neighbor = dfs_bad(dfs_bad, best, -1, 0);
    for (int child : adj[best]){
        if (dp[child] == dp[best] - 1){
            bad_neighbor = child;
        }
    }

    vector<int> neighbors;
    for (int child : adj[best]){
        if (child != bad_neighbor){
            neighbors.push_back(child);
        }
    }

    cout << neighbors[0] + 1 << ' ' << best + 1 << ' ' << neighbors[1] + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}