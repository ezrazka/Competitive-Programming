#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<int, int>> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
        mx = max(mx, v[i].se);
    }
    sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
        if (a.se == b.se) return a.fi < b.fi;
        return a.se < b.se;
    });

    vector<int> in(mx + 1, -1), out(mx + 1, -1);
    for (int i = 0; i < n; i++){
        in[v[i].fi] = i, out[v[i].se] = i;
    }

    vector<vector<pair<int, int>>> queries(mx + 1);
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        queries[l].push_back({r, i});
    }

    ordered_set<int> st;
    ordered_set<int> ends;
    int cur = 0;
    for (int i = 0; i < n; i++){
        if (v[i].fi >= cur){
            st.insert(i);
            ends.insert(v[i].se);
            cur = v[i].se;
        }
    }

    vector<int> vans(q);
    for (int l = 1; l <= mx; l++){
        for (auto [r, i] : queries[l]){
            vans[i] = st.order_of_key(*ends.upper_bound(r));
        }
        if (!st.empty() && v[*st.begin()].fi == l){
            for (int i = *st.begin(); i < n; i++){
                if (st.lower_bound(i) != st.end()){
                    break;
                }
                if (v[i].fi >= cur){
                    st.insert(i);
                    cur = v[i].se;
                }
            }
            st.erase(*st.begin());
        }
    }

    for (int i = 0; i < q; i++){ // amortize it, sort it
        cout << vans[i] << " \n"[i == q - 1];
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