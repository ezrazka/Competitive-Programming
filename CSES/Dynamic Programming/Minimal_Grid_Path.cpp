#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    string ans;
    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<pair<int, int>> cur;
    vector<pair<int, int>> nex;
    cur.push_back({0, 0});
    vis[0][0] = true;
    while (!cur.empty()){
        ans += v[cur[0].fi][cur[0].se];
        char mn = 'Z';
        for (auto [i, j] : cur){
            if (i + 1 < n) mn = min(mn, v[i + 1][j]);
            if (j + 1 < n) mn = min(mn, v[i][j + 1]);
        }
        for (auto [i, j] : cur){
            if (i + 1 < n && v[i + 1][j] == mn && !vis[i + 1][j]){
                vis[i + 1][j] = true;
                nex.push_back({i + 1, j});
            }
            if (j + 1 < n && v[i][j + 1] == mn && !vis[i][j + 1]){
                vis[i][j + 1] = true;
                nex.push_back({i, j + 1});
            }
        }
        cur = nex;
        nex.clear();
    }
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