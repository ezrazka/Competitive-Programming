#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (auto p : {0, 1}) {
        ordered_set<int> st;
        if (!((0 & 1) ^ p)) st.insert(0);
        for (int i = 1, pref = 0; i <= n; i++) {
            pref += (((i & 1) ^ p) ? a[i] : -a[i]);
            if (((i & 1) ^ p)) ans += st.order_of_key(pref);
            else st.insert(pref);
        }
    }
    cout << ans << '\n';

    /*
        must be odd length
        * every odd index > every even index (1-based)

        a b c -> a + c > b
        a b c d e ->
            a + c > b && (a + c - b) + e > d ||
            b + d > c && a + e > (b + d - c) ||
            c + e > d && a + (c + e - d) > b
                         ^ this part always reduces to a + c + e > b + d

        if it fulfills the second condition,
        can we guarantee >=1 of the first condition must be fulfilled?
        worst case: x 2x+1 x 2x+1 x
        3x < 4x + 2
        i think so
    */
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
