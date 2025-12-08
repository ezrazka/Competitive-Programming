#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(2, -INF));
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0] + a[i - 1], a[i - 1]);
        if (k % 2 == 1){
            dp[i][1] = max({
                dp[i - 1][0] + a[i - 1] + b[i - 1], a[i - 1] + b[i - 1],
                dp[i - 1][1] + a[i - 1], a[i - 1]
            });
        }
    }

    int ans = -INF;
    for (int i = 1; i <= n; i++){
        ans = max({ans, dp[i][0], dp[i][1]});
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