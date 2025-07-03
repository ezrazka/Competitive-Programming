#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<bool> dp(k + 1);
    dp[0] = false;
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < n; j++){
            if (i - v[j] >= 0 && !dp[i - v[j]]){
                dp[i] = true;
            }
        }
    }
    cout << (dp[k] ? "First\n" : "Second\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}