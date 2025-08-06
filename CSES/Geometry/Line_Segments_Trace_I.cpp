#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v[i] = {(b - a) / m, a};
    }

    auto is_obsolete = [&](const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c){
        return (c.se - a.se) * (b.fi - c.fi) < (c.se - b.se) * (a.fi - c.fi);
    };
    
    vector<int> vans(m + 1);
    {
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>&b){
            return a.se - a.fi < b.se - b.fi;
        });
        deque<int> hull;
        for (int i = 0; i < n; i++){
            while (hull.size() >= 2 && is_obsolete(v[hull[hull.size() - 1]], v[hull[hull.size() - 2]], v[i])){
                hull.pop_back();
            }
            hull.push_back(i);
        }
        for (int i = 0; i <= m; i++){
            while (hull.size() >= 2 && v[hull[0]].fi * i + v[hull[0]].se < v[hull[1]].fi * i + v[hull[1]].se){
                hull.pop_front();
            }
            vans[i] = max(vans[i], v[hull[0]].fi * i + v[hull[0]].se);
        }
    }
    {
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>&b){
            return a.se - a.fi > b.se - b.fi;
        });
        deque<int> hull;
        for (int i = 0; i < n; i++){
            while (hull.size() >= 2 && is_obsolete(v[hull[hull.size() - 1]], v[hull[hull.size() - 2]], v[i])){
                hull.pop_back();
            }
            hull.push_back(i);
        }
        for (int i = 0; i <= m; i++){
            while (hull.size() >= 2 && v[hull[0]].fi * i + v[hull[0]].se < v[hull[1]].fi * i + v[hull[1]].se){
                hull.pop_front();
            }
            vans[i] = max(vans[i], v[hull[0]].fi * i + v[hull[0]].se);
        }
    }
    for (int i = 0; i <= m; i++){
        cout << vans[i] << " \n"[i == m];
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