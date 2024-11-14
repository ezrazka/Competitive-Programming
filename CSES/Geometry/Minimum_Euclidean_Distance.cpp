#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int square(int x){
    return x * x;
}

void solve(){
    int n; cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n;i ++){
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end());

    auto cmp = [&](pii a, pii b){
        return make_pair(a.se, a.fi) < make_pair(b.se, b.fi);
    };
    
    set<pii, decltype(cmp)> st(cmp);
    int d = LLONG_MAX;
    for (int i = 0; i < n; i++){
        set<pii> to_remove;
        for (auto it = st.lower_bound({1e9, floor(v[i].se - sqrt(d))}); it != st.end(); it++){
            if (square(v[i].se - it->se) > d) break;
            if (square(v[i].fi - it->fi) <= d){
                d = min(d, square(v[i].fi - it->fi) + square(v[i].se - it->se));
            } else if (square(v[i].fi - it->fi) > d){
                to_remove.insert(*it);
            }
        }
        for (auto x : to_remove){
            st.erase(x);
        }
        st.insert(v[i]);
    }
    cout << d << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}