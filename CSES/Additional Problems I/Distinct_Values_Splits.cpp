#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dp(n + 1), pref(n + 1);
    dp[0] = 1, pref[0] = 1;
    set<int> st;
    for (int i = 1, j = 1; i <= n; i++){
        while (st.find(a[i]) != st.end()){
            st.erase(a[j]);
            j++;
        }
        st.insert(a[i]);

        dp[i] = (pref[i - 1] - (j - 2 < 0 ? 0 : pref[j - 2])) % MOD;
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }
    cout << (dp[n] + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}