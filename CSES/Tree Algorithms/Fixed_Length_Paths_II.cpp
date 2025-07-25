#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"
 
void solve(){
    int n, k1, k2; cin >> n >> k1 >> k2;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<bool> dead(n);
    vector<int> sz(n);
    auto dfs_sz = [&](auto self, int node, int parent) -> void {
        sz[node] = 1;
        for (int child : adj[node]){
            if (child != parent && !dead[child]){
                self(self, child, node);
                sz[node] += sz[child];
            }
        }
    };
    
    auto dfs_centroid = [&](auto self, int node, int parent, int root) -> int {
        for (int child : adj[node]){
            if (child != parent && !dead[child]){
                if (sz[child] > sz[root] / 2){
                    return self(self, child, node, root);
                }
            }
        }
        return node;
    };
    
    vector<int> depth(n);
    auto dfs_depth = [&](auto self, int node, int parent, vector<int>& depths) -> void {
        depth[node] = depth[parent] + 1;
        for (int child : adj[node]){
            if (child != parent && !dead[child]){
                self(self, child, node, depths);
            }
        }
        depths.push_back(depth[node]);
    };
    
    vector<int> dp(n);
    auto dfs_cd = [&](auto self, int node) -> void {
        dfs_sz(dfs_sz, node, -1);
        int centroid = dfs_centroid(dfs_centroid, node, -1, node);
        
        vector<vector<int>> child_depths;
        depth[centroid] = 0;
        for (int centroid_child : adj[centroid]){
            if (!dead[centroid_child]){
                vector<int> depths;
                dfs_depth(dfs_depth, centroid_child, centroid, depths);
                child_depths.push_back(depths);
            }
        }
 
        vector<vector<int>> child_pref_depth_counts;
        for (vector<int> depths : child_depths){
            int max_depth = min(k2, *max_element(depths.begin(), depths.end()));
            vector<int> pref_depth_counts(max_depth + 2);
            for (int depth : depths){
                if (depth <= k2){
                    pref_depth_counts[depth + 1]++;
                }
            }
            child_pref_depth_counts.push_back(pref_depth_counts);
        }
        
        int child_max_depth = 0;
        for (vector<int> pref_depth_counts : child_pref_depth_counts){
            int max_depth = pref_depth_counts.size() - 2;
            child_max_depth = max(child_max_depth, max_depth);
        }
 
        vector<int> pref_depth_sums(child_max_depth + 2);
        pref_depth_sums[1] = 2;
        for (vector<int> pref_depth_counts : child_pref_depth_counts){
            int max_depth = pref_depth_counts.size() - 2;
            for (int i = 1; i <= max_depth; i++){
                pref_depth_sums[i + 1] += pref_depth_counts[i + 1];
            }
        }
 
        for (int i = 0; i < child_pref_depth_counts.size(); i++){
            vector<int>& pref_depth_counts = child_pref_depth_counts[i];
            int max_depth = pref_depth_counts.size() - 2;
            for (int i = 2; i <= max_depth + 1; i++){
                pref_depth_counts[i] += pref_depth_counts[i - 1];
            }
        }
        for (int i = 2; i <= child_max_depth + 1; i++){
            pref_depth_sums[i] += pref_depth_sums[i - 1];
        }
        
        for (int i = 0; i < child_pref_depth_counts.size(); i++){
            vector<int> pref_depth_counts = child_pref_depth_counts[i];
            int max_depth = pref_depth_counts.size() - 2;
            for (int j = 1; j <= max_depth; j++){
                dp[centroid] += (pref_depth_counts[j + 1] - pref_depth_counts[j]) * (
                    (
                        (k2 - j + 1 <= child_max_depth + 1 ? pref_depth_sums[k2 - j + 1] : pref_depth_sums.back()) -
                        (k1 - j >= 0 ? k1 - j <= child_max_depth + 1 ? pref_depth_sums[k1 - j] : pref_depth_sums.back() : 0)
                    ) -
                    (
                        (k2 - j + 1 <= max_depth + 1 ? pref_depth_counts[k2 - j + 1] : pref_depth_counts.back()) -
                        (k1 - j >= 0 ? k1 - j <= max_depth + 1 ? pref_depth_counts[k1 - j] : pref_depth_counts.back() : 0)
                    )
                );
            }
        }
        dp[centroid] /= 2;
 
        dead[centroid] = true;
        for (int centroid_child : adj[centroid]){
            if (!dead[centroid_child]){
                self(self, centroid_child);
            }
        }
        dead[centroid] = false;
    };
    dfs_cd(dfs_cd, 0);
 
    cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}