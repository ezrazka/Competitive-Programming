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

    int mn = v[0], mx = v[0], sum = v[0];
    cout << mn << ' ' << mx << ' ' << fixed << setprecision(4) << 1.0 * sum << '\n';
    for (int i = 1; i < n; i++){
        mn = min(mn + 1, v[i]);
        mx = max(mx + 1, v[i]);
        sum += v[i] + i;
        cout << mn << ' ' << mx << ' ' << fixed << setprecision(4) << 1.0 * sum / (i + 1) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}