#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> w(n - 1, vector<int>(m)), v(n, vector<int>(m - 1));
    vector<vector<int>> p(n - 1, vector<int>(m)), q(n, vector<int>(m - 1));
    for (int i = 0; i < n - 1; i++) for (int j = 0; j < m; j++) cin >> w[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m - 1; j++) cin >> v[i][j];
    for (int i = 0; i < n - 1; i++) for (int j = 0; j < m; j++) { char c; cin >> c; p[i][j] = c - '0'; };
    for (int i = 0; i < n; i++) for (int j = 0; j < m - 1; j++) { char c; cin >> c; q[i][j] = c - '0'; };

    auto merge = [&](const pair<int, bool> &a, const pair<int, bool> &b) -> pair<int, bool> {
        return {a.first + b.first, a.second && b.second};
    };

    vector<vector<bool>> vis(n - 1, vector<bool>(m - 1));
    auto dfs = [&](auto self, int i, int j) -> pair<int, bool> {
        if (!((0 <= i && i < n - 1) && (0 <= j && j < m - 1))) return {0ll, false};
        if (vis[i][j]) return {0ll, true};
        vis[i][j] = true;

        pair<int, bool> res = {w[i][j] - w[i][j + 1] + v[i][j] - v[i + 1][j], true};
        if (!p[i][j]) res = merge(res, self(self, i, j - 1));
        if (!p[i][j + 1]) res = merge(res, self(self, i, j + 1));
        if (!q[i][j]) res = merge(res, self(self, i - 1, j));
        if (!q[i + 1][j]) res = merge(res, self(self, i + 1, j));
        return res;
    };

    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m - 1; j++){
            if (!vis[i][j]){
                pair<int, bool> res = dfs(dfs, i, j);
                if (res.second) ans += max(0ll, res.first);
            }
        }
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