#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    vector<vector<vector<int>>> grid(n, vector<vector<int>>(m, vector<int>(30)));
    vector<vector<vector<int>>> target(n, vector<vector<int>>(m, vector<int>(30)));
    for (int bit = 0; bit < 30; bit++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                grid[i][j][bit] = (a[i][j] >> bit) & 1;
                target[i][j][bit] = (b[i][j] >> bit) & 1;
            }
        }
    }

    bool ok = true;
    for (int bit = 0; bit < 30; bit++){
        vector<int> whites(n), blacks(m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (target[i][j][bit] == 0) whites[i]++;
                else blacks[j]++;
            }
        }

        queue<pii> q;
        for (int i = 0; i < n; i++) if (whites[i] == m) q.push({i, 0});
        for (int j = 0; j < m; j++) if (blacks[j] == n) q.push({j, 1});
        while (!q.empty()){
            if (q.front().se == 0){
                int row = q.front().fi; q.pop();
                for (int j = 0; j < m; j++){
                    if (target[row][j][bit] == 0){
                        if (++blacks[j] == n) q.push({j, 1});
                    }
                    target[row][j][bit] = 2;
                }
            } else {
                int col = q.front().fi; q.pop();
                for (int i = 0; i < n; i++){
                    if (target[i][col][bit] == 1){
                        if (++whites[i] == m) q.push({i, 0});
                    }
                    target[i][col][bit] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (target[i][j][bit] != 2 && grid[i][j][bit] != target[i][j][bit]){
                    ok = false;
                }
            }
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

    // for all bits from 1 to 30
    // its basically just grids of black and white
    // we can turn any row white, and any column black
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}