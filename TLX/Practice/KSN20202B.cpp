#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct circle {
    int x, y, r, c;
};

void solve(){
    int n; cin >> n;
    vector<circle> circles;
    {
        circle start;
        cin >> start.x >> start.y;
        start.r = 0;
        start.c = 0;
        circles.push_back(start);
    }
    {
        circle end;
        cin >> end.x >> end.y;
        end.r = 0;
        end.c = 0;
        circles.push_back(end);
    }
    for (int i = 0; i < n; i++){
        circle c;
        cin >> c.x >> c.y >> c.r >> c.c;
        circles.push_back(c);
    }

    vector<int> ord_x(n + 2), ord_y(n + 2);
    {
        iota(ord_x.begin(), ord_x.end(), 0);
        sort(ord_x.begin(), ord_x.end(), [&](int i, int j){
            return circles[i].x - circles[i].r < circles[j].x - circles[j].r;
        });
    }
    {
        iota(ord_y.begin(), ord_y.end(), 0);
        sort(ord_y.begin(), ord_y.end(), [&](int i, int j){
            return circles[i].y - circles[i].r < circles[j].y - circles[j].r;
        });
    }

    vector<int> vertical(n + 2);
    int n_vertical = 0;
    {
        int best_r = -1e18;
        for (int i : ord_x){
            int l = circles[i].x - circles[i].r;
            int r = circles[i].x + circles[i].r;
            if (l > best_r) n_vertical++;
            best_r = max(best_r, r);
            vertical[i] = n_vertical;
        }
    }
    vector<int> horizontal(n + 2);
    int n_horizontal = n_vertical;
    {
        int best_r = -1e18;
        for (int i : ord_y){
            int l = circles[i].y - circles[i].r;
            int r = circles[i].y + circles[i].r;
            if (l > best_r) n_horizontal++;
            best_r = max(best_r, r);
            horizontal[i] = n_horizontal;
        }
    }
    int n_components = n_vertical + n_horizontal;
    vector<vector<int>> nodes(n_components + 1);
    {
        for (int i = 0; i < n + 2; i++){
            nodes[vertical[i]].push_back(i);
            nodes[horizontal[i]].push_back(i);
        }
    }
    {
        vector<int> dist(n_components + 1, 1e18);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[horizontal[0]] = 0;
        pq.push({dist[horizontal[0]], horizontal[0]});
        while (!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (int subnode : nodes[node]){
                int child = (horizontal[subnode] == node ? vertical[subnode] : horizontal[subnode]);
                if (subnode == 0 && child == vertical[subnode]) continue;
                if (dist[node] + circles[subnode].c < dist[child]){
                    dist[child] = dist[node] + circles[subnode].c;
                    pq.push({dist[child], child});
                }
            }
        }
        int ans = min(dist[vertical[1]], dist[horizontal[1]]);
        cout << (ans == 1e18 ? -1 : ans) << '\n';
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