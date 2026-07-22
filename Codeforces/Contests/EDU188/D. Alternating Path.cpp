#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> team(n, -1);
    auto dfs = [&](auto self, int node, int parent) -> pair<bool, pair<int, int>> {
        pair<bool, pair<int, int>> ans = {true, {0, 0}};
        for (int child : adj[node]){
            if (child != parent){
                if (team[node] == team[child]) ans.first = false;
                if (team[child] != -1) continue;
                team[child] = 3 - team[node];
                auto [ok, p] = self(self, child, node);
                ans.first = ans.first & ok;
                ans.second.first += p.first;
                ans.second.second += p.second;
            }
        }
        if (team[node] == 1) ans.second.first++;
        else ans.second.second++;
        return ans;
    };

    int ans = 0;
    for (int node = 0; node < n; node++){
        if (team[node] != -1) continue;
        team[node] = 1;
        auto [ok, p] = dfs(dfs, node, -1);
        if (ok) ans += max(p.first, p.second);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
