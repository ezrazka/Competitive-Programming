#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector<pair<int, int>> b(m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }

    bool ok = false;
    for (int i = 1; i < m; i++) {
        auto [date, month] = b[i];
        pair<int, int> prev = (date == 1 ? make_pair(a[month - 1], month - 1) : make_pair(date - 1, month));
        if (prev == b[i - 1]) continue;
        {
            auto [prev_date, prev_month] = prev;
            pair<int, int> prevprev = (prev_date == 1 ? make_pair(a[prev_month - 1], prev_month - 1) : make_pair(prev_date - 1, prev_month));
            if (prevprev == b[i - 1]) ok = true;
        }
    }
    cout << (ok ? "YA\n" : "TIDAK\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
