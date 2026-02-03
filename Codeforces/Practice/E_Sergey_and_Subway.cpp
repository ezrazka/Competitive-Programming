#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> cnt(n, vector<int>(2, 0));
    vector<int> sum(n, 0);
    auto dfs = [&](auto self, int node, int parent) -> void {
        cnt[node][0]++;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                cnt[node][0] += cnt[child][1];
                cnt[node][1] += cnt[child][0];
                sum[node] += sum[child] + cnt[child][0];
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<int> sum_reroot(n, 0);
    auto reroot = [&](auto self, int node, int parent, vector<int> cnt_parent, int sum_parent) -> void {
        sum_reroot[node] = sum[node] + (sum_parent + cnt_parent[0]);

        vector<int> total_cnt(2, 0);
        int total_sum = 0;
        for (int child : adj[node]){
            if (child != parent){
                total_cnt[0] += cnt[child][0];
                total_cnt[1] += cnt[child][1];
                total_sum += sum[child];
            }
        }

        for (int child : adj[node]){
            if (child != parent){
                vector<int> next_cnt_parent = {
                    (total_cnt[1] - cnt[child][1]) + cnt_parent[1] + 1,
                    (total_cnt[0] - cnt[child][0]) + cnt_parent[0]
                };
                int next_sum_parent = ((total_sum - sum[child]) + sum_parent) + ((total_cnt[0] - cnt[child][0]) + cnt_parent[0]);

                self(self, child, node, next_cnt_parent, next_sum_parent);
            }
        }
    };
    reroot(reroot, 0, -1, {0, 0}, 0);

    int ans = 0;
    for (int node = 0; node < n; node++){
        ans += sum_reroot[node];
    }
    ans /= 2;
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}