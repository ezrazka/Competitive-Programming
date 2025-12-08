#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int l = 1, r = 1e9, ans = 0;
    {
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
            if (i - 3 >= 0) dp[i] = min(dp[i], dp[i - 3] + max({a[i], a[i - 1], a[i - 2]}) - min({a[i], a[i - 1], a[i - 2]}));
        }
        ans = dp[n];
    }
    cout << ans << '\n';
    /*
    perhaps I can do Push DP,
    from dp[i], i find the 

    1 100 99 98 97 96 95 1
    either ur equal to prev, or both are equal to prev

    100 99 95 85 1 1
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}