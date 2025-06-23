#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }

    multiset<int> dp;
    for (int i = 0; i < n; i++){
        auto it = dp.upper_bound(r[i]);
        if (it != dp.end()){
            dp.erase(it);
        }
        dp.insert(l[i]);
        cout << dp.size() << " \n"[i == n - 1];
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