#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    set<int> remaining;
    set<pair<int, pair<int, int>>> st;
    for (int i = 0; i < n; i++){
        remaining.insert(i);
        st.insert({max(a[i], a[(i + 1) % n]), {i, (i + 1) % n}});
    }

    int ans = 0;
    for (int _ = 0; _ < n - 1; _++){
        while (remaining.find(st.begin()->se.fi) == remaining.end() || remaining.find(st.begin()->se.se) == remaining.end()){
            st.erase(st.begin());
        }

        auto cheapest = st.begin()->fi;
        auto [i, j] = st.begin()->se;

        ans += cheapest;

        remaining.erase(j);
        auto it = remaining.upper_bound(i);
        if (it == remaining.end()) it = remaining.begin();
        int k = *it;

        a[i] = cheapest;
        st.insert({max(a[i], a[k]), {i, k}});
    }
    cout << ans << '\n';

    /*
    have a priority queue storing:
    all adjacent pairs and their indices, {max(a[i], a[j]), {i, j}}
    
    insert() ->
        * get the cheapest, add to the ans
        * mark j as visited, set a[i] to max(a[i], a[j])
        * push (max(a[i], a[k]), {i, k}), where k is the first remaining element to the right
    query() -> pop while i or j is already visited
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