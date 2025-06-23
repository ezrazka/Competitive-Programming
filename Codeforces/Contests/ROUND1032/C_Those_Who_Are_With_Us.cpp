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
    vector<vector<int>> v(n, vector<int>(m));
    int mx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
            mx = max(mx, v[i][j]);
        }
    }
    
    int cnt_mx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cnt_mx += (v[i][j] == mx);
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (v[i - 1][j - 1] == mx);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int cnt = pref[n][j] - pref[0][j] - pref[n][j - 1] + pref[0][j - 1] + \
                      pref[i][m] - pref[i][0] - pref[i - 1][m] + pref[i - 1][0] - \
                      (v[i - 1][j - 1] == mx);
            if (cnt == cnt_mx){
                cout << mx - 1 << '\n';
                return;
            }
        }
    }

    cout << mx << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}