#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    int total = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            total += a[i][j];
        }
    }

    int need = total / 2;
    pair<int, int> idx;
    for (int i = 1; i <= n; i++){
        for (int j = m; j >= 1; j--){
            need -= a[i][j];
            if (need == 0){
                idx = {i, j};
                i = n, j = 1;
            }
        }
    }

    cout << (total / 2) * ((total + 1) / 2) << '\n';
    for (int _ = 0; _ < idx.first - 1; _++) cout << 'D';
    for (int _ = 0; _ < idx.second - 1; _++) cout << 'R';
    cout << 'D';
    for (int _ = 0; _ < m - idx.second + 1; _++) cout << 'R';
    for (int _ = 0; _ < n - idx.first; _++) cout << 'D';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}