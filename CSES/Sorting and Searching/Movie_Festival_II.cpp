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
    vector<pii> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end(), [&](pii a, pii b){
        return make_pair(a.se, a.fi) < make_pair(b.se, b.fi);
    });

    int ans = 0;
    multiset<int> ms;
    for (int i = 0; i < k; i++){
        ms.insert(0);
    }
    for (int i = 0; i < n; i++){
        auto it = ms.upper_bound(v[i].fi);
        if (it == ms.begin()) continue;
        ms.erase(--it);
        ms.insert(v[i].se);
        ans++;
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