#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> vans(n);
    ordered_set<int> ost;
    multiset<int> mst;
    for (int i = n - 1; i >= 0; i--){
        vans[i] = max(ost.order_of_key(a[i]), ost.size() - ost.order_of_key(a[i]) - mst.count(a[i]));
        ost.insert(a[i]);
        mst.insert(a[i]);
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
