#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int calc(int n){
    return n * (n - 1) / 2;
}

void solve(){
    int n, m, q; cin >> n >> m >> q;

    int ans = n * m;
    vector<vector<bool>> locked(n + 1, vector<bool>(m + 1));
    vector<vector<vector<pair<int, int>>>> loc(n + 1, vector<vector<pair<int, int>>>(m + 1, vector<pair<int, int>>(2, {-1, -1})));
    vector<set<int>> d(n + m);
    for (int k = 1; k <= n + m - 1; k++){
        int i = max(1ll, n - k + 1) - m, j = max(1ll, k - n + 1) - m, c = 1, p = 1;
        while (i < 1 || j < 1){
            p & 1 ? i++ : j++;
            p ^= 1;
        }
        while (i <= n && j <= m){
            loc[i][j][k & 1] = {k, c};
            p ? i++ : j++;
            p ^= 1, c++;
        }
        d[k].insert(0);
        d[k].insert(c);
        ans += calc(c - 1);
    }

    while (q--){
        int i, j; cin >> i >> j;
        locked[i][j] = !locked[i][j];
        if (locked[i][j]) ans--;
        else ans++;
        for (int p : {0, 1}){
            if (loc[i][j][p] != pair<int, int>{-1, -1}){
                auto [k, c] = loc[i][j][p];
                if (locked[i][j]){
                    auto it = d[k].insert(c).first;
                    ans -= calc(*next(it) - *prev(it) - 1);
                    ans += calc(*next(it) - *it - 1);
                    ans += calc(*it - *prev(it) - 1);
                } else {
                    auto it = d[k].find(c);
                    ans += calc(*next(it) - *prev(it) - 1);
                    ans -= calc(*next(it) - *it - 1);
                    ans -= calc(*it - *prev(it) - 1);
                    d[k].erase(it);
                }
            }
        }
        cout << ans << '\n';
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