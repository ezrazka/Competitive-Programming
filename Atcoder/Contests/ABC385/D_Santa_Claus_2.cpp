#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define x first
#define y second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    map<int, set<int>> xs, ys;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        xs[a].insert(b);
        ys[b].insert(a);
    }
    vector<pair<char, int>> s(m);
    for (int i = 0; i < m; i++){
        cin >> s[i].x >> s[i].y;
    }

    pii cur = {x, y};
    int houses = 0;
    for (auto [c, steps] : s){
        if (c == 'L'){
            cur.x -= steps;

            auto it = ys[cur.y].lower_bound(cur.x);
            while (it != ys[cur.y].end() && *it <= cur.x + steps){
                houses++;
                xs[*it].erase(cur.y);
                ys[cur.y].erase(it);
                it = ys[cur.y].lower_bound(cur.x);
            }
        }
        if (c == 'R'){
            auto it = ys[cur.y].lower_bound(cur.x);
            while (it != ys[cur.y].end() && *it <= cur.x + steps){
                houses++;
                xs[*it].erase(cur.y);
                ys[cur.y].erase(it);
                it = ys[cur.y].lower_bound(cur.x);
            }

            cur.x += steps;
        }
        if (c == 'D'){
            cur.y -= steps;
            
            auto it = xs[cur.x].lower_bound(cur.y);
            while (it != xs[cur.x].end() && *it <= cur.y + steps){
                houses++;
                ys[*it].erase(cur.x);
                xs[cur.x].erase(it);
                it = xs[cur.x].lower_bound(cur.y);
            }
        }
        if (c == 'U'){
            auto it = xs[cur.x].lower_bound(cur.y);
            while (it != xs[cur.x].end() && *it <= cur.y + steps){
                houses++;
                ys[*it].erase(cur.x);
                xs[cur.x].erase(it);
                it = xs[cur.x].lower_bound(cur.y);
            }

            cur.y += steps;
        }
    }
    cout << cur.x << ' ' << cur.y << ' ' << houses << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}