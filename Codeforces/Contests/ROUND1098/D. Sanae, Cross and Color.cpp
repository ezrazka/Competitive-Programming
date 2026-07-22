#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<vector<int>> points(n + 1);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points[x].push_back(y);
    }

    int ans = 0;
    set<int> st;
    for (int x = 1; x <= n; x++) {
        if (points[x].empty()) continue;
        for (int y : points[x]) st.insert(y);
        ans += st.size();
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
