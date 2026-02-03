#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

struct point {
    int x, y;

    bool operator<(const point& other) const {
        return x < other.x;
    }
};

void solve(){
    int n; cin >> n;
    point s, t;
    cin >> s.x >> s.y;
    cin >> t.x >> t.y;
    vector<point> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x;
    for (int i = 0; i < n; i++) cin >> a[i].y;

    map<int, set<int>> mp;
    for (int i = 0; i < n; i++){
        mp[a[i].x].insert(a[i].y);
    }

    vector<map<int, int>> dp(2);
    dp[0][s.x] = 0;
    dp[1][s.x] = 0;

    pair<int, set<int>> prev = {s.x, set<int>{s.y}};
    for (auto [x, ys] : mp){
        auto [prev_x, prev_ys] = prev;
        dp[0][x] = (x - prev_x) + abs(*ys.begin() - *ys.rbegin()) + min(
            dp[0][prev_x] + abs(*ys.rbegin() - *prev_ys.begin()),
            dp[1][prev_x] + abs(*ys.rbegin() - *prev_ys.rbegin())
        );
        dp[1][x] = (x - prev_x) + abs(*ys.begin() - *ys.rbegin()) + min(
            dp[0][prev_x] + abs(*ys.begin() - *prev_ys.begin()),
            dp[1][prev_x] + abs(*ys.begin() - *prev_ys.rbegin())
        );
        prev = make_pair(x, ys);
    }
    {
        auto [prev_x, prev_ys] = prev;
        cout << (t.x - prev_x) + min(
            dp[0][prev_x] + abs(t.y - *prev_ys.begin()),
            dp[1][prev_x] + abs(t.y - *prev_ys.rbegin())
        ) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}