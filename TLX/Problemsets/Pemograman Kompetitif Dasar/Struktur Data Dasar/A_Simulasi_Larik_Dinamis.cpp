#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int q; cin >> q;
    vector<vector<pii>> v(1);
    while (q--){
        string qq; cin >> qq;
        if (qq == "new"){
            v.push_back({});
        }
        if (qq == "add"){
            int l, x, y; cin >> l >> x >> y; l--;
            if (v[l].empty()){
                v[l].push_back({y, x});
            } else {
                v[l].push_back({y + v[l].back().fi, x});
            }
        }
        if (qq == "out"){
            int l, z; cin >> l >> z; l--;
            int lo = 0, hi = v[l].size() - 1, res = -1;
            while (lo <= hi){
                int mid = (lo + hi) / 2;

                if (v[l][mid].fi < z){
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                    res = v[l][mid].se;
                }
            }
            cout << res << '\n';
        }
    }
}