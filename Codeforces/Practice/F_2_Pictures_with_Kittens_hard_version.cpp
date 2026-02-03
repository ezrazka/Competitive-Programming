#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    vector<deque<int>> pref(x + 1);
    dp[0][0] = 0;
    pref[0].push_back(0);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= x; j++){
            if (j - 1 < 0){
                dp[i][j] = -1;
                continue;
            }

            while (!pref[j - 1].empty() && pref[j - 1].front() < i - k) pref[j - 1].pop_front();
            if (pref[j - 1].empty()){
                dp[i][j] = -1;
                continue;
            }

            int before = dp[pref[j - 1].front()][j - 1];
            dp[i][j] = a[i] + before;
        }
        for (int j = 0; j <= x; j++){
            if (dp[i][j] != -1){
                while (!pref[j].empty() && dp[pref[j].back()][j] <= dp[i][j]) pref[j].pop_back();
                pref[j].push_back(i);
            }
        }
    }

    int ans = -1;
    for (int i = n - k + 1; i <= n; i++){
        ans = max(ans, dp[i][x]);
    }
    cout << ans << '\n';
    /*
    dp[i][j] = a[i] + max(dp[x][j - 1], i - k <= x <= i - 1);
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}