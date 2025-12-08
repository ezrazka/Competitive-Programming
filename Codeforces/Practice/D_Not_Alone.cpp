#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int INF = 1e18;

int calc(vector<int> &v){
    int n = v.size() - 1;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 1]));
        if (i - 3 >= 0) dp[i] = min(dp[i], dp[i - 3] + max({v[i], v[i - 1], v[i - 2]}) - min({v[i], v[i - 1], v[i - 2]}));
    }
    return dp[n];
}

void solve(){
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    int ans = INF;
    for (int i = 0; i < 3; i++){
        ans = min(ans, calc(v));
        rotate(v.begin() + 1, v.begin() + 2, v.end());
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