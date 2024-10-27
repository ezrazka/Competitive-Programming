#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    vector<vector<char>> v(8, vector<char>(8));
    vector<bool> is(8, true), js(8, true);
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> v[i][j];
            if (v[i][j] == '#'){
                is[i] = false;
                js[j] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (is[i] && js[j]){
                ans++;
            }
        }
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