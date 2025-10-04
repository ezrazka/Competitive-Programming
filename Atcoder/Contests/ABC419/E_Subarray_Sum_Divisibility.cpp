#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, l; cin >> n >> m >> l;
    vector<vector<int>> v(l + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v[i % l + 1].push_back(x);
    }

    vector<vector<int>> cost(l + 1, vector<int>(m));
    for (int i = 1; i <= l; i++){
        for (int k = 0; k < m; k++){
            for (int x : v[i]){
                cost[i][k] += (k - x + m) % m;
            }
        }
    }

    vector<vector<int>> dp(l + 1, vector<int>(m, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= l; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                dp[i][j] = min(dp[i][j], dp[i - 1][(j - k + m) % m] + cost[i][k]);
            }
        }
    }
    cout << dp[l][0] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}