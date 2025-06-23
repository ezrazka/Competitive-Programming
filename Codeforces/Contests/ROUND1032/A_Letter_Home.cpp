#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, s; cin >> n >> s;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    int ans = min(abs(mx - s), abs(mn - s)) + mx - mn;
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