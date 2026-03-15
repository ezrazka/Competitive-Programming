#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct point {
    int x, y;

    bool operator<(const point &other) const {
        return make_pair(x, y) < make_pair(other.x, other.y);
    }
};

void solve(){
    int r, c, n; cin >> r >> c >> n;
    vector<point> p(n);
    map<int, int> mp_x, mp_y;
    map<point, int> mp;
    for (int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        mp_x[p[i].x] ^= 1;
        mp_y[p[i].y] ^= 1;
        mp[p[i]] ^= 1;
    }

    int cnt_x = 0, cnt_y = 0;
    for (auto [key, val] : mp_x) if (val) cnt_x++;
    for (auto [key, val] : mp_y) if (val) cnt_y++;

    int ans = cnt_x * c + cnt_y * r - 2 * cnt_x * cnt_y;
    for (auto [key, val] : mp){
        if (val){
            if (mp_x[key.x] ^ mp_y[key.y]) ans--;
            else ans++;
        }
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