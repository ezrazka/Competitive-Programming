#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> q(n);
    multiset<int> r;
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < n; i++) { int x; cin >> x; r.insert(x); }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int div = (k < q[i] ? 0 : (k - q[i]) / (q[i] + 1));
        auto it = r.upper_bound(div);
        if (it == r.begin()) continue;
        it--;
        r.erase(it);
        ans++;
    }
    cout << ans << '\n';

    /*
    for a fixed q and r, optimally, x = r + 1, y = q * (r + 1) + r
    its greedy to iterate over q in any order as long as we take the option that
    eliminates the least options for later, whch is the largest r

    iterate over q, find largest r such that q * (r + 1) + r <= k
    r <= (k - q) / (q + 1)
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