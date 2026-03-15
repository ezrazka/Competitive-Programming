#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> rs(n + 1, -1);
    for (int _ = 0; _ < m; _++){
        int l, r; cin >> l >> r;
        rs[r] = max(rs[r], l);
    }
    for (int r = 1; r <= n; r++){
        rs[r] = max(rs[r], rs[r - 1]);
    }

    vector<int> dp(n + 1), pref(n + 1);
    dp[0] = 2, pref[0] = 2;
    for (int r = 1; r <= n; r++){
        dp[r] = (pref[r - 1] - (rs[r] - 1 < 0 ? 0 : pref[rs[r] - 1])) % MOD;
        pref[r] = (pref[r - 1] + dp[r]) % MOD;
    }
    cout << (dp[n] + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}