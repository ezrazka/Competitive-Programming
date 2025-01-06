#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    vector<vector<int>> pref(mx + 1, vector<int>(n + 1));
    for (int num = 0; num <= mx; num++){
        for (int i = 1; i <= n; i++){
            pref[num][i] = pref[num][i - 1] + (v[i - 1] == num);
        }
    }

    auto merge = [&](pii a, pii b) -> pii {
        if (a.fi == b.fi) return {a.fi, (a.se + b.se) % MOD};
        if (a.fi < b.fi) return a;
        return b;
    };

    while (q--){
        int l, r; cin >> l >> r; l--, r--;
        { // if theres at least 1 zero, ans is (1, number of zeros)
            int ans = pref[0][r + 1] - pref[0][l];
            if (ans > 0){
                cout << (r - l + 1) - 1 << ' ' << ans << '\n';
                continue;
            }
        }
        { // else if theres at least 2 of any number, ans is (2, sum of NC2 of all numbers)
            int ans = 0;
            for (int num = 0; num <= mx; num++){
                int freq = pref[num][r + 1] - pref[num][l];
                ans += freq * (freq - 1) / 2;
            }
            if (ans > 0){
                cout << (r - l + 1) - 2 << ' ' << ans % MOD << '\n';
                continue;
            }
        }
        { // else, freq is always 0 or 1, therefore solve with DP
            int mx_xor = 1 << (32 - __builtin_clz(mx));
            vector<pii> dp(mx_xor, {1e9, 0}); // dp[i] = {minimum steps to reach state, number of ways}
            for (int num = 0; num <= mx; num++){
                if (pref[num][r + 1] - pref[num][l] > 0){
                    vector<pii> next(mx_xor, {1e9, 0});
                    next[num] = {1, 1};
                    for (int mask = 0; mask < mx_xor; mask++){
                        next[mask ^ num] = merge(next[mask ^ num], {dp[mask].fi + 1, dp[mask].se});
                    }
                    for (int mask = 0; mask < mx_xor; mask++){
                        dp[mask] = merge(dp[mask], next[mask]);
                    }
                }
            }
            if (dp[0].fi == 1e9){
                cout << -1 << '\n';
            } else {
                cout << (r - l + 1) - dp[0].fi << ' ' << dp[0].se << '\n';
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}