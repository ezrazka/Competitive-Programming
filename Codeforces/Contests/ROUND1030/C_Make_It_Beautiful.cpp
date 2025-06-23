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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += __builtin_popcount(v[i]);
    }

    vector<int> empty(60);
    for (int i = 0; i < n; i++){
        for (int bit = 0; bit < 60; bit++){
            if (!(v[i] & (1ll << bit))) empty[bit]++;
        }
    }

    for (int bit = 0; bit < 60; bit++){
        ans += min(empty[bit], k / (1ll << bit));
        k -= min(empty[bit], k / (1ll << bit)) * (1ll << bit);
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