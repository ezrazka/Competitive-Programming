#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int INF = 0x3f3f3f3f;

vector<vector<int>> solve2(int n, int m, vector<vector<int>> v){
    vector<vector<int>> vans(n, vector<int>(m, INF));
    int prev_pair[n][n];
    int cur_area[n][n];
    memset(cur_area, 0x3f, sizeof(cur_area));
    for (int j = m - 1; j >= 0; j--){
        // for each pair, update minimum value with area
        int mn[n][n];
        memset(mn, 0x3f, sizeof(mn));
        for (int x = 0; x < n; x++){
            for (int y = x + 1; y < n; y++){
                // update
                mn[x][y] = min(mn[x][y], cur_area[x][y]);
                // change
                if (v[x][j] && v[y][j]){
                    prev_pair[x][y] = j - 1;
                    while (prev_pair[x][y] != -1 && (!v[x][prev_pair[x][y]] || !v[y][prev_pair[x][y]])){
                        prev_pair[x][y]--;
                    }
                    if (prev_pair[x][y] != -1){
                        cur_area[x][y] = (j - prev_pair[x][y] + 1) * (y - x + 1);
                    } else {
                        cur_area[x][y] = INF;
                    }
                }
                // update
                mn[x][y] = min(mn[x][y], cur_area[x][y]);
            }
        }

        // from left to right use RMU idea without pq
        for (int x = 0; x < n; x++){
            for (int y = x + 1; y < n; y++){
                vans[y][j] = min(vans[y][j], mn[x][y]);
            }
            for (int y = n - 2; y >= x; y--){
                vans[y][j] = min(vans[y][j], vans[y + 1][j]);
            }
        }
    }
    return vans;
    /*
    idea: wlog n < m, then we simply solve keeping track of all pairs n^2 * m worst case (2.5e5^(3/2))

    instead of using priority queues, we can update them for a fixed left, and then suffix minimum

    */
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            v[i][j] = c - '0';
        }
    }
    
    if (n > m){
        swap(n, m);
        vector<vector<int>> w(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                w[i][j] = v[j][i];
            }
        }
        auto vans = solve2(n, m, w);
        for (int j = 0; j < m; j++){
            for (int i = 0; i < n; i++){
                cout << (vans[i][j] == INF ? 0 : vans[i][j]) << ' ';
            }
            cout << '\n';
        }
    } else {
        auto vans = solve2(n, m, v);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << (vans[i][j] == INF ? 0 : vans[i][j]) << ' ';
            }
            cout << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}