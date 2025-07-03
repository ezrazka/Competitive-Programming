#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++){
        for (int j : {0, 1, 2}){
            for (int k : {0, 1, 2}){
                if (j != k){
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + v[i - 1][j]);
                }
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}