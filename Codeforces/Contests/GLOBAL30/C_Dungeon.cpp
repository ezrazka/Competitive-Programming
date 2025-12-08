#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];
    sort(a.begin(), a.end());

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return c[i] < c[j];
    });

    int x = 0;
    for (int i = 0; i < m; i++){
        if (c[ord[i]] == 0) x++;
        else break;
    }

    sort(ord.begin(), ord.begin() + x, [&](int i, int j){
        return b[i] < b[j];
    });
    sort(ord.begin() + x, ord.end(), [&](int i, int j){
        return b[i] < b[j];
    });

    multiset<int> ams(a.begin(), a.end());

    int ans = 0;
    for (int i = x; i < m; i++){
        auto it = ams.lower_bound(b[ord[i]]);
        if (it == ams.end()) break;
        ams.insert(max(*it, c[ord[i]]));
        ams.erase(it);
        ans++;
    }

    multiset<int> bms;
    for (int i = 0; i < x; i++){
        bms.insert(b[ord[i]]);
    }

    for (int x : ams){
        auto it = bms.upper_bound(x);
        if (!bms.empty() && it != bms.begin()){
            it = prev(it);
            bms.erase(it);
            ans++;
        }
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