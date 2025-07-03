#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<vector<pair<int, int>>> queries(n);
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r; l--, r--;
        queries[l].push_back({r, i});
    }

    vector<int> vans(q);
    vector<int> st;
    for (int l = n - 1; l >= 0; l--){
        while (!st.empty() && v[l] >= v[st.back()]){
            st.pop_back();
        }
        st.push_back(l);
        for (auto [r, i] : queries[l]){
            vans[i] = upper_bound(st.rbegin(), st.rend(), r) - st.rbegin();
        }
    }

    for (int i = 0; i < q; i++){
        cout << vans[i] << '\n';
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