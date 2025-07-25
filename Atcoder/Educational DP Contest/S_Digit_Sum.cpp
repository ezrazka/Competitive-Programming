#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    string s; cin >> s;
    int d; cin >> d;
    int n = s.length();
    s = "0" + s;

    vector<int> dp(d);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        vector<int> next(d);

        int congruence = 0;
        for (int j = 0; j < i; j++){
            congruence += s[j] - '0';
            congruence %= d;
        }

        for (int j = 0; j < d; j++){
            for (int dd = 0; dd < 10; dd++){
                next[(j + dd) % d] += dp[j];
                if (j == congruence && dd > s[i] - '0'){
                    next[(j + dd) % d]--;
                    next[(j + dd) % d] += MOD;
                }
                next[(j + dd) % d] %= MOD;
            }
        }

        dp = next;
    }
    cout << (dp[0] - 1 + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}