#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> v[i][0];
    for (int i = 0; i < n; i++) cin >> v[i][1];
    for (int i = 0; i < n; i++) if (v[i][0] > v[i][1]) swap(v[i][0], v[i][1]);
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += v[i][1] - v[i][0];
    }
    int mn = 1e9;
    int mx = -1e9;
    for (int i = 0; i < n; i++){
        if (i != 0){
            mn = min(mn, max(0ll, v[i][0] - mx));
        }
        mx = max(mx, v[i][1]);
    }
    ans += 2 * mn;
    cout << ans << '\n';
    // 1 2
    // 3 4 -> 4
    // 1 2
    // 4 3 -> 4
    // 1 3
    // 2 4 -> 2
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}