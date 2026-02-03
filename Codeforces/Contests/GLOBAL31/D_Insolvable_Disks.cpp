#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> upper(n + 1, INF);
    upper[1] = a[2] - a[1];
    upper[n] = a[n] - a[n - 1];
    for (int i = 2; i <= n - 1; i++){
        upper[i] = min(a[i + 1] - a[i], a[i] - a[i - 1]);
    }

    // {ways, lower bound}
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(2, {-INF, 0}));
    dp[1][0] = {0, upper[1]};
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(
            make_pair(dp[i - 1][0].first, upper[i]),
            make_pair(dp[i - 1][1].first, upper[i] - dp[i - 1][1].second)
        );
        dp[i][1] = max(
            make_pair(dp[i - 1][0].first + 1, -upper[i]),
            make_pair(dp[i - 1][1].first + 1, -min())
        );
        dp[i][1].second = -dp[i][1].second;
    }
    cout << max(dp[n][0], dp[n][1]).first << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}