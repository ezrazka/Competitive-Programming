#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    int ans = m;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        if (u != 0) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}]++;
        ans--;
    }

    vector<bool> vis(n);
    auto dfs = [&](auto self, int node) -> void {
        vis[node] = true;
        for (int child : adj[node]) {
            if (!vis[child]) self(self, child);
        }
    };
    dfs(dfs, 0);

    if (accumulate(vis.begin(), vis.end(), 0) != n) {
        cout << -1 << '\n';
    } else {
        for (auto[key, val] : mp) ans -= val - 1;
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
