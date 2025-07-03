#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (i == j){
                dp[i][j] = v[i];
            } else {
                dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}