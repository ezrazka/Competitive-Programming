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
    int n; cin >> n;
    string s; cin >> s;
    int m = s.length();

    vector<int> pi(m);
    for (int i = 1; i < m; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if (s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < min(i + 1, m); j++){
            int temp = j;
            while (temp > 0){
                temp = pi[temp - 1];
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++){
        ans = (ans * 26) % MOD;
    }
    for (int i = 0; i < m; i++){
        ans = (ans - dp[n][i] + MOD) % MOD;
    }
    
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}