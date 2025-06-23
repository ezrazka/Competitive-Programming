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
    vector<pair<pair<int, int>, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se.fi >> v[i].se.se;
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        auto [a, b] = v[i];
        auto [dx, dy] = a;
        auto [x, y] = b;

        if (
            dx == 1 && dy == -1 && dx * (s - x) == dy * (0 - y) ||
            dx == -1 && dy == 1 && dx * (0 - x) == dy * (s - y) ||
            dx == 1 && dy == 1 && dx * (s - x) == dy * (s - y) ||
            dx == -1 && dy == -1 && dx * (0 - x) == dy * (0 - y)
        ){
            ans++;
        }
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