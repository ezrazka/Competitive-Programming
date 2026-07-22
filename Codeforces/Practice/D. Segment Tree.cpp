#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<pair<int, int>> ops(2 * n + 1); // 1: add, -1: remove
    for (int i = 0; i < n; i++) {
        ops[a[i].first] = {i, 1};
        ops[a[i].second] = {i, -1};
    }

    vector<vector<int>> adj(n);
    {
        set<pair<int, int>> open;
        int edges = 0;
        for (int k = 1; k <= 2 * n; k++) {
            int i = ops[k].first;
            if (ops[k].second == 1) {
                for (auto [r, j] : open) {
                    if (a[i].second < r) break;
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    edges++;
                }
                open.insert({a[i].second, i});
                if (edges > n - 1) {
                    cout << "NO\n";
                    return;
                }
            } else {
                open.erase({a[i].second, i});
            }
        }
        if (edges < n - 1) {
            cout << "NO\n";
            return;
        }
    }

    {
        vector<bool> vis(n);
        auto dfs = [&](auto self, int node) -> void {
            if (vis[node]) return;
            vis[node] = true;
            for (int child : adj[node]) {
                self(self, child);
            }
        };
        dfs(dfs, 0);
        if (accumulate(vis.begin(), vis.end(), 0ll) < n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
