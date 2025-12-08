#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int x, y, k; cin >> x >> y >> k;

    vector<int> v(x);
    iota(v.begin(), v.end(), 1);

    ordered_set<int> ost(v.begin(), v.end());
    while (x--){
        for (int i = ost.size() / y * y - 1; i >= 0; i -= y){
            ost.erase(ost.find_by_order(i));
        }
        if (ost.empty()){
            break;
        }
    }

    if (ost.size() > k){
        cout << -1 << '\n';
    } else {
        cout << *ost.find_by_order(k - 1) << '\n';
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