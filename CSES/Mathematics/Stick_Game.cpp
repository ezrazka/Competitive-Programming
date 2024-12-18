#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"


void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++){
        cin >> v[i];
    }

    bitset<1000001> dp;
    dp[0] = 1;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}