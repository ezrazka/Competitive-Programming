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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    ordered_set<int> st;
    int inversions = 0;
    for (int i = 0; i < k; i++){
        st.insert(v[i]);
        inversions += st.size() - st.order_of_key(v[i] + 1);
    }
    
    cout << inversions << ' ';
    for (int i = k; i < n; i++){
        st.insert(v[i]);
        inversions += st.size() - st.order_of_key(v[i] + 1);
        st.erase(st.upper_bound(v[i - k]));
        inversions -= st.order_of_key(v[i - k]);
        cout << inversions << " \n"[i == n - 1];
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