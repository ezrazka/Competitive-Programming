#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
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

    int m = (1ll << (32 - __builtin_clz(*max_element(v.begin(), v.end())))) - 1;
    vector<true> dp(m + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++){
        for (int j = )
    }

    for (int i = 0)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}