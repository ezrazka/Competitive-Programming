#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, a, b; cin >> n >> a >> b;

    vector<ld> dp(6 * n + 1);
    dp[0] = 1;
    for (int _ = 0; _ < n; _++){
        vector<ld> next(6 * n + 1);
        for (int i = 0; i <= 6 * n; i++){
            for (int j = max(0ll, i - 6); j < i; j++){
                next[i] += (1.0 / 6) * dp[j];
            }
        }
        dp = next;
    }

    ld ans = 0;
    for (int i = a; i <= b; i++){
        ans += dp[i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}