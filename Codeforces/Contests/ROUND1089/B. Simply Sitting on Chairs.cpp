#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    int ans = 0;
    vector<bool> vis(n + 1);
    for (int i = 1, cur = 0; i <= n; i++) {
        if (vis[i]) cur--;
        if (i != p[i] && vis[p[i]]) cur--;
        vis[i] = false;
        vis[p[i]] = true;
        if (vis[i]) cur++;
        if (i != p[i] && vis[p[i]]) cur++;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
