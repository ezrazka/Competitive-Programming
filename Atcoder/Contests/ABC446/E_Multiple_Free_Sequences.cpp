#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int m, a, b; cin >> m >> a >> b;

    vector<vector<vector<pair<int, int>>>> adj(m, vector<vector<pair<int, int>>>(m));
    for (int s1 = 0; s1 < m; s1++){
        for (int s2 = 0; s2 < m; s2++){
            adj[s2][(a * s2 + b * s1) % m].emplace_back(s1, s2);
        }
    }

    vector<vector<bool>> vis(m, vector<bool>(m));
    int ans = m * m;
    auto dfs = [&](auto self, const pair<int, int> &node) -> void {
        if (vis[node.first][node.second]) return;
        vis[node.first][node.second] = true;
        ans--;
        for (const pair<int, int> &child : adj[node.first][node.second]){
            self(self, child);
        }
    };

    dfs(dfs, {0, 0});
    for (int i = 0; i < m; i++){
        dfs(dfs, {0, i});
        dfs(dfs, {i, 0});
    }
    cout << ans << '\n';
    /*
    a graph of M^2 nodes, count how many nodes dont lead to (0, 0)
    OR M^2 - how many lead to (0, 0)
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