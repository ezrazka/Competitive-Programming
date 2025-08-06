#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }

    set<int> st1, st2;
    for (int i = 0; i < n; i++){
        st1.insert(v[i].fi + v[i].se);
        st2.insert(v[i].fi - v[i].se);
        int best1 = abs(*st1.begin() - *st1.rbegin());
        int best2 = abs(*st2.begin() - *st2.rbegin());
        cout << max(best1, best2) << '\n';
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