#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (v[i - 1][j - 1] == 'g');
        }
    }

    int gold = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            gold += (v[i][j] == 'g');
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (v[i - 1][j - 1] == '.'){
                int lost = pref[min(n, i + k - 1)][min(m, j + k - 1)] - \
                           pref[max(0ll, i - k)][min(m, j + k - 1)] - \
                           pref[min(n, i + k - 1)][max(0ll, j - k)] + \
                           pref[max(0ll, i - k)][max(0ll, j - k)];
                ans = max(ans, gold - lost);
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