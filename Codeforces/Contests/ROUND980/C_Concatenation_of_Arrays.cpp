#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<pii> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i].fi >> v[i].se;
        }
        sort(v.begin(), v.end(), [&](pii a, pii b){
            return a.fi + a.se < b.fi + b.se;
        });

        for (int i = 0; i < n; i++){
            cout << v[i].fi << ' ' << v[i].se << ' ';
        }
        cout << '\n';
    }
}