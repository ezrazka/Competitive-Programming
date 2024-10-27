#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    int ans = 1;
    for (int i = 0; i < n; i++){
        ans = (ans * m) % MOD;
    }

    vector<int> dp(n + 1), pref(n + 1);
    dp[0] = 1, pref[0] = 1;
    for (int i = 1; i <= n; i++){
        if (i < k){
            dp[i] = (dp[i - 1] * m) % MOD;
        } else {
            dp[i] = ((pref[i - 1] - pref[i - k]) * (m - 1)) % MOD;
        }
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }

    cout << (ans - dp[n] + MOD) % MOD << '\n';
    /*
    1. How does it work?
        * It counts the number of ways such that there are no K consecutive of the same color
        * Every transition,
            we count the number of ways for the canvas to end with 1 to K - 1 of the same color
    2. How could I have come up with it myself?
        * Observation 1:
            Notice that a canvas is always reachable if there exists K consecutive same color squares
        * Observation 2:
            To count the number of valid canvases, a lot of inclusion-exclusion is required,
            To count the number of invalid canvases, no inclusion-exclusion is required,
                and prefix sums can be utilized to optimize computation
    3. What can I do to make sure I can come up with it next time it appears?
        *
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