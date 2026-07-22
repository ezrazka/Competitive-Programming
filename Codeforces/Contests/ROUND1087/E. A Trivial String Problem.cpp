#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<int> pi(n), dp(n);
    while (q--){
        int l, r; cin >> l >> r; l--, r--;
        int len = r - l + 1;
        int ans = 1;
        pi[0] = 0, dp[0] = 1;
        for (int i = 1; i < len; i++){
            int j = pi[i - 1];
            while (j > 0 && s[l + i] != s[l + j]) j = pi[j - 1];
            if (s[l + i] == s[l + j]) j++;
            pi[i] = j;
            dp[i] = (j == 0 ? 1 : dp[j - 1] + dp[i - j]);
            ans += dp[i];
        }
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
