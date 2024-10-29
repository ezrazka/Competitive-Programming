#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < k - 1; i++){
        v.push_back(v[i]);
    }
    n += k - 1;

    int ans = 1e18;
    set<int> st;
    for (int i = 0, j = 0; i < n; i++){
        while (j < n && (st.empty() || max(*st.rbegin(), v[j]) - min(*st.begin(), v[j]) + 1 <= k) && st.find(v[j]) == st.end()){
            st.insert(v[j]);
            j++;
        }
        ans = min(ans, k - (int) st.size());
        st.erase(v[i]);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}