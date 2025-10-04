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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, bool> found;
    for (int i = 0; i < n; i++){
        found[v[i]] = true;
    }

    bool ok = (found.size() - found[-1] <= 1) && !found[0];
    cout << (ok ? "YES\n" : "NO\n");
    // none are 0, diff is 0 (possible)
    // have 0, no 1, diff is 1 (impossible)
    // have 0 1, no 2, diff is 2 (impossible)
    // have 0 1 2, no 3, diff is 3 (impossible)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}