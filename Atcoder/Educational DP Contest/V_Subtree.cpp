#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        dp[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                dp[node] *= (dp[child] + 1);
                dp[node] %= m;
            }
        }
    };
    dfs(dfs, 0, -1);
    
    vector<int> dp2(n);
    auto dfs2 = [&](auto self, int node, int parent, int dp_parent) -> void {
        dp2[node] = (dp[node] * (dp_parent + 1)) % m;

        vector<int> children;
        for (int child : adj[node]){
            if (child != parent){
                children.push_back(child);
            }
        }

        if (children.empty()){
            return;
        }

        int sz = children.size();
        vector<int> pref(sz);
        pref[0] = (dp[children[0]] + 1);
        pref[0] %= m;
        for (int i = 1; i < sz; i++){
            pref[i] = pref[i - 1] * (dp[children[i]] + 1);
            pref[i] %= m;
        }

        vector<int> suff(sz);
        suff[sz - 1] = (dp[children[sz - 1]] + 1);
        suff[sz - 1] %= m;
        for (int i =  sz - 2; i >= 0; i--){
            suff[i] = suff[i + 1] * (dp[children[i]] + 1);
            suff[i] %= m;
        }

        for (int i = 0; i < sz; i++){
            int child = children[i];
            int next_p = (dp_parent + 1);
            if (i - 1 >= 0){
                next_p *= pref[i - 1];
                next_p %= m;
            }
            if (i + 1 < sz){
                next_p *= suff[i + 1];
                next_p %= m;
            }
            self(self, child, node, next_p);
        }
    };
    dfs2(dfs2, 0, -1, 0);

    for (int i = 0; i < n; i++){
        cout << dp2[i] << '\n';
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