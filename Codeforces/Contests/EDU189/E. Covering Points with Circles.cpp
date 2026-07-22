#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, r; cin >> n >> r;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    int offset = ceil(sqrt((ld) 3 * r * r));

    auto floor = [](int a, int b) -> int {
        return (a < 0 ? (a + 1) / b - 1 : a / b);
    };

    vector<pair<int, int>> vans;
    for (auto [x, y] : p) {
        pair<int, int> p1 = {floor(x, 2 * offset) * (2 * offset), floor(y, 2 * r) * (2 * r)};
        pair<int, int> p2 = {floor(x - offset, 2 * offset) * (2 * offset) + offset, floor(y - r, 2 * r) * (2 * r) + r};

        for (const pair<int, int> &c : {
            p1, {p1.first + 2 * offset, p1.second}, {p1.first, p1.second + 2 * r}, {p1.first + 2 * offset, p1.second + 2 * r},
            p2, {p2.first + 2 * offset, p2.second}, {p2.first, p2.second + 2 * r}, {p2.first + 2 * offset, p2.second + 2 * r},
        }) {
            int dx = abs(x - c.first);
            int dy = abs(y - c.second);
            if (dx * dx + dy * dy <= r * r) {
                vans.push_back(c);
                break;
            }
        }
    }

    sort(vans.begin(), vans.end());
    vans.erase(unique(vans.begin(), vans.end()), vans.end());

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++) {
        cout << vans[i].first << ' ' << vans[i].second << '\n';
    }

    // cover all the points that fit in hexagonal packing
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
