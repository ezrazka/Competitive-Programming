#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }

    vector<int> ends(m, 1e18);
    for (int i = 0; i < n; i++){
        ends[v[i].fi - 1] = min(ends[v[i].fi - 1], v[i].se - 1);
    }
    for (int i = m - 2; i >= 0; i--){
        ends[i] = min(ends[i], ends[i + 1]);
    }

    int ans = 0;
    int l = 0, r = 0;
    while (l < m){
        while (r < m && r < ends[l]){
            r++;
        }
        ans += r - l;
        l++;
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