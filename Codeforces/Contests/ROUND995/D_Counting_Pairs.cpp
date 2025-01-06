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
    int n, x, y; cin >> n >> x >> y;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    x = sum - x, y = sum - y;
    swap(x, y);

    int ans = 0;
    ordered_set<int> oset;
    for (int i = 0; i < n; i++){
        int at_least_x = n - oset.order_of_key(x - v[i]);
        int more_than_y = n - oset.order_of_key(y - v[i] + 1);
        ans += at_least_x - more_than_y;
        oset.insert(v[i]);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}