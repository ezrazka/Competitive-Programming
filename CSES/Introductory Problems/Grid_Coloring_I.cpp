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
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == 'A' || v[i][j] == 'B'){
                cout << ((i + j) & 1 ? 'C' : 'D');
            }
            if (v[i][j] == 'C' || v[i][j] == 'D'){
                cout << ((i + j) & 1 ? 'A' : 'B');
            }
        }
        cout << '\n';
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