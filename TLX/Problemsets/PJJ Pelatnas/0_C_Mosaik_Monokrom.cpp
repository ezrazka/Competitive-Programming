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
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int f = 1; f <= 5; f++){
        freopen(("mosaik_" + to_string(f) + ".in").c_str(), "r", stdin);
        freopen(("mosaik_" + to_string(f) + ".out").c_str(), "w", stdout);
        solve();
    }
    return 0;
}