#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> l, r;
    for (int i = 1; i <= n; i++){
        if (l.empty() || l.back() < a[i]){
            l.push_back(a[i]);
        }
    }
    for (int i = n; i >= 1; i--){
        if (r.empty() || r.back() < a[i]){
            r.push_back(a[i]);
        }
    }
    vector<int> v = l;
    for (int i = (int) r.size() - 2; i >= 0; i--){
        v.push_back(r[i]);
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(v.size() + 1, vector<int>(2)));
    int ans = 0;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= v.size(); j++){
            // take
            if (j - 1 >= 0 && a[i] == v[j - 1]){ // if j -> j, '1' -> '0'
                dp[i][j][0] += dp[i - 1][j - 1][0];
                dp[i][j][0] += dp[i - 1][j][0];
                dp[i][j][0] += dp[i - 1][j][1];
                if (j == v.size()){
                    ans += dp[i][j][0] % MOD;
                    debug(ans);
                    ans %= MOD;
                }
            } else {
                // cannot take if it breaks monotonicity
                if (j - 1 >= 0 && v[j - 1] >= a[i]){
                    if (j == v.size() || v[j] < a[i]){
                        dp[i][j][1] += dp[i - 1][j][0]; // we can only take '1' if j -> j, else no
                    } else {
                        dp[i][j][0] += dp[i - 1][j][0];
                    }
                    dp[i][j][1] += dp[i - 1][j][1];
                }
            }
            // no take
            dp[i][j][0] += dp[i - 1][j][0];
            dp[i][j][1] += dp[i - 1][j][1];
            // mod
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
            /*
            9
            3 5 5 7 4 6 7 2 4
                    3       48
            */
            cout << i << '-' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << '\n';
        }
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