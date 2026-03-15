#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sz(n), sz2(n);
    vector<vector<int>> dp(n, vector<int>(2));
    vector<vector<int>> sums(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        sz[node] = a[node];
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                sz[node] += sz[child];
                sz2[node] += sz2[child] + sz[child];
            }
        }
        for (int child : adj[node]){
            if (child != parent){
                dp[node][1] = max(dp[node][1], sz2[node] - sz2[child] + dp[child][1]);
            }
        }

        int largest = -1;
        for (int child : adj[node]){
            if (child != parent){
                if (largest == -1 || sums[child].size() > sums[largest].size()){
                    largest = child;
                }
            }
        }

        if (largest == -1){
            sums[node].push_back(sz[node]);
            return;
        }
        
        swap(sums[node], sums[largest]);
        vector<int> others;
        for (int child : adj[node]){
            if (child != parent && child != largest){
                while (others.size() < sums[child].size()){
                    others.push_back(0);
                }
            }
        }
        for (int child : adj[node]){
            if (child != parent && child != largest){
                for (int depth = 0; depth < sums[child].size(); depth++){
                    others[others.size() - depth - 1] = max(others[others.size() - depth - 1], sums[child][sums[child].size() - depth - 1]);
                }
            }
        }

        dp[node][0] = sz2[node];
        for (int depth = 0; depth < others.size(); depth++){
            dp[node][1] = max(dp[node][1], sz2[node] + (int) (sums[node].size() - depth) * others[others.size() - depth - 1]);
        }
        for (int depth = 0; depth < others.size(); depth++){
            dp[node][1] = max(dp[node][1], sz2[node] + (int) (others.size() - depth) * sums[node][sums[node].size() - depth - 1]);
        }

        for (int depth = 0; depth < others.size(); depth++){
            sums[node][sums[node].size() - depth - 1] = max(sums[node][sums[node].size() - depth - 1], others[others.size() - depth - 1]);
        }
        sums[node].push_back(sz[node]);
    };
    dfs(dfs, 0, -1);

    for (int node = 0; node < n; node++){
        cout << max(dp[node][0], dp[node][1]) << " \n"[node == n - 1];
    }
    /*
    for each node, store:
    * maximum subtree sum per depth
    with small-to-large merging should be O(n)

    the transition:
    merge everything but the longest (chmax)
    so we have (1) longest and (2) combined_others
    for each depth in combined_others, compare with longest depth
    compare all depths in longest < combined_others depth
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}