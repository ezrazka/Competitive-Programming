#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}

    const bool operator<(const point& other) const {
        return make_pair(x, y) < make_pair(other.x, other.y);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<point> coords(n + 1);
    for (int i = 1; i <= n; i++){
        coords[i].x = coords[i - 1].x + (s[i - 1] == 'R') - (s[i - 1] == 'L');
        coords[i].y = coords[i - 1].y + (s[i - 1] == 'U') - (s[i - 1] == 'D');
    }

    map<point, vector<int>> mp;
    for (int i = 0; i <= n; i++){
        mp[coords[i]].push_back(i);
    }

    auto check = [&](point p, int l, int r){
        auto it = lower_bound(mp[p].begin(), mp[p].end(), l);
        return it != mp[p].end() && *it <= r;
    };

    while (q--){
        int x, y, l, r; cin >> x >> y >> l >> r;
        int mid_x = coords[r].x + coords[l - 1].x - x;
        int mid_y = coords[r].y + coords[l - 1].y - y;
        bool ok = (
            check(point(x, y), 0, l - 1) ||
            check(point(mid_x, mid_y), l, r - 1) ||
            check(point(x, y), r, n)
        );
        cout << (ok ? "YES\n" : "NO\n");
    }
    /*
    we can assume that for each i, l <= i <= r,
    its (x, y) = coords[l - 1] + delta(i, r)
    and (x, y) = coords[l - 1] + (coords[r] - coords[i])
    so to look up coords[i], we can use the following formula:
    coords[i] = coords[r] + coords[l - 1] - (x, y)
    the value of i itself is arbitrary and irrelevant since all values of i exist in the map
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}