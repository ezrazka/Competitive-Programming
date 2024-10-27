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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }
    vector<vector<int>> right(n, vector<int>(m));
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            int l = i, r = n - 1, res = -1;
            while (l <= r){
                int mid = (l + r) / 2;

                if (pref[mid + 1] - pref[i] <= b[j]){
                    l = mid + 1;
                    res = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            right[i][j] = res;
        }
    }

    vector<vector<int>> dp(n + 2, vector<int>(m + 1, 1e18));
    for (int j = 0; j <= m; j++){
        dp[n + 1][j] = 0;
    }
    for (int j = m; j >= 1; j--){
        for (int i = n; i >= 1; i--){
            dp[i][j] = min(dp[i][j], dp[right[i - 1][j - 1] + 1][j] + m - j);
            if (j < m){
                dp[i][j] = min(dp[i][j], dp[right[i - 1][j - 1] + 1][j + 1] + m - j);
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }
    }
    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= m; j++){
    //         cout << i << ' ' << j << '\n';
    //         debug(dp[i][j]);
    //     }
    // }
    cout << (dp[1][1] == 1e18 ? -1 : dp[1][1]) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}