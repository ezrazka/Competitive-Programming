#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >>n >> m;
    vector<pii> v(m);
    for (int i = 0; i < m; i++){
        cin >> v[i].fi >> v[i].se;
    }

    set<pii> st;
    for (int k = 0; k < m; k++){
        for (auto [di, dj] : {pii(1, 2), pii(-1, 2), pii(1, -2), pii(-1, -2), pii(2, 1), pii(-2, 1), pii(2, -1), pii(-2, -1)}){
            int i = v[k].fi, j = v[k].se;
            int ii = i + di, jj = j + dj;
            if (ii <= n && ii >= 1 && jj <= n && jj >= 1){
                st.insert({ii, jj});
            }
            st.insert({i, j});
        }
    }
    cout << n * n - st.size() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}