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
    string s; cin >> s;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + (s[i - 1] == '+' ? 1 : -1);
    }

    int ans = 0;
    {
        vector<ordered_set<int>> osts(3);
    
        osts[0].insert(pref[0]);
        for (int i = 1; i <= n; i++){
            int congruence = (pref[i] % 3 + 3) % 3;
            ans += osts[congruence].size() - osts[congruence].order_of_key(pref[i]);
            osts[congruence].insert(pref[i]);
        }
    }
    cout << ans << '\n';

    /*
    by pigeonhole principle, if there is at least 2 more '-'s than '+'s,
    there will ALWAYS exist a pair of consecutive '-'s

    therefore we only need to find the number of substrings such that
    {the number of '+'s} minus 3 * {the number of '-'s} is divisible by 3 and non negative
    
    for each three mods we can store an ordered set and count how many fulfill non-negativity
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}