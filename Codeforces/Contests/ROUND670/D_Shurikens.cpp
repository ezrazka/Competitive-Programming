#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    vector<int> vans(n);
    set<int> unused;
    set<pair<int, int>> used; // {vans[i], i} (i in monotonically decreasing order)
    for (int _ = 0, i = 0; _ < 2 * n; _++){
        char c; cin >> c;
        if (c == '+'){
            unused.insert(i++);
        } else {
            int x; cin >> x;
            int j;
            {
                auto it = used.upper_bound({x, 0});
                int min_j = (it == used.end() ? 0 : it->second);
                if (unused.lower_bound(min_j) == unused.end()) {
                    cout << "NO\n";
                    return;
                }
                j = *unused.lower_bound(min_j);
            }
            vans[j] = x;
            {
                unused.erase(j);
                auto it = used.emplace(x, i).first;
                if (next(it) != used.end() && next(it)->second >= i){
                    used.erase(it);
                    continue;
                }
                while (it != used.begin() && i >= prev(it)->second){
                    used.erase(prev(it));
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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