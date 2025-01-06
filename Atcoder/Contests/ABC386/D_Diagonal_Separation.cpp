#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> whites;
    map<int, int> rows, cols;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y; x--, y--;
        char c; cin >> c;
        if (c == 'B') rows[x] = max(rows[x], y + 1), cols[y] = max(cols[y], x + 1);
        else whites.push_back({x, y});
    }

    {
        if (!rows.empty()){
            auto it = --rows.end();
            while (it != rows.begin()){
                auto it2 = prev(it);
                rows[it2->fi] = max(rows[it2->fi], rows[it->fi]);
                it--;
            }
        }
    }
    {
        if (!cols.empty()){
            auto it = --cols.end();
            while (it != cols.begin()){
                auto it2 = prev(it);
                cols[it2->fi] = max(cols[it2->fi], cols[it->fi]);
                it--;
            }
        }
    }

    for (auto [x, y] : whites){
        if (rows.lower_bound(y) == rows.end() || cols.lower_bound(y) == cols.end()) continue;
        if (x <= cols.lower_bound(y)->se - 1 && y <= rows.lower_bound(x)->se - 1){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}