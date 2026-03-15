#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

struct point {
    int x, y;
};

void solve(){
    int n; cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }

    int f4 = 0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        f4 += abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
    }

    int min_x = INF, max_x = -INF;
    int min_y = INF, max_y = -INF;
    for (int i = 0; i < n; i++){
        min_x = min(min_x, p[i].x);
        max_x = max(max_x, p[i].x);
        min_y = min(min_y, p[i].y);
        max_y = max(max_y, p[i].y);
    }

    for (int i = 0; i < n; i++){
        if (
            p[i].x == min_x && p[i].y == min_y ||
            p[i].x == min_x && p[i].y == max_y ||
            p[i].x == max_x && p[i].y == min_y ||
            p[i].x == max_x && p[i].y == max_y
        ){
            for (int i = 3; i <= n; i++){
                cout << f4 << " \n"[i == n];
            }
            return;
        }
    }

    int f3 = 0;
    for (int i = 0; i < n; i++){
        for (auto [min_x, max_x, min_y, max_y] : initializer_list<array<int, 4>>{
            {min_x, max_x, INF, -INF},
            {INF, -INF, min_y, max_y},
            {min_x, -INF, min_y, -INF},
            {min_x, -INF, INF, max_y},
            {INF, max_x, min_y, -INF},
            {INF, max_x, INF, max_y}
        }){
            min_x = min(min_x, p[i].x);
            max_x = max(max_x, p[i].x);
            min_y = min(min_y, p[i].y);
            max_y = max(max_y, p[i].y);
            f3 = max(f3, 2 * ((max_x - min_x) + (max_y - min_y)));
        }
    }

    for (int i = 3; i <= n; i++){
        cout << (i == 3 ? f3 : f4) << " \n"[i == n];
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