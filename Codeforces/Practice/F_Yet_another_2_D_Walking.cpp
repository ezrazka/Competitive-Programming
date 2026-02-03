#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct point {
    int x, y;

    bool operator<(const point &other) const {
        return make_pair(x, -y) < make_pair(other.x, -other.y);
    }
};

int calc(const point &a, const point &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve(){
    int n; cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    map<int, point> levels_min, levels_max;
    for (const point &p : points){
        int level = max(p.x, p.y);
        if (levels_min.find(level) == levels_min.end()){
            levels_min[level] = p;
            levels_max[level] = p;
        } else {
            levels_min[level] = min(levels_min[level], p);
            levels_max[level] = max(levels_max[level], p);
        }
    }
    
    map<int, int> dp[2];
    {
        dp[0][0] = 0;
        dp[1][0] = 0;
        int prev_level = 0;
        point prev_mn = {0, 0}, prev_mx = {0, 0};
        for (auto [level, _] : levels_min){
            const point &mn = levels_min[level];
            const point &mx = levels_max[level];
            // cout << level << " (" << mn.x << ", " << mn.y << ") (" << mx.x << ", " << mx.y << ") " << '\n';
            dp[0][level] = min(
                dp[0][prev_level] + calc(prev_mn, mx) + calc(mx, mn), // mn from mn
                dp[1][prev_level] + calc(prev_mx, mx) + calc(mx, mn)  // mn from mx
            );
            dp[1][level] = min(
                dp[0][prev_level] + calc(prev_mn, mn) + calc(mn, mx), // mx from mn
                dp[1][prev_level] + calc(prev_mx, mn) + calc(mn, mx)  // mx from mx
            );
            prev_level = level;
            prev_mn = mn, prev_mx = mx;
            // debug(dp[0][level]);
            // debug(dp[1][level]);
        }
    }
    cout << min(dp[0].rbegin()->second, dp[1].rbegin()->second) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}