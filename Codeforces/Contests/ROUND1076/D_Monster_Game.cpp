#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.rbegin(), a.rend());

    vector<int> pref(n);
    pref[0] = b[0];
    for (int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + b[i];
    }

    int ans = 0;
    for (int hits = 1; hits <= n; hits++){
        int x = a[hits - 1];
        int levels = upper_bound(pref.begin(), pref.end(), hits) - pref.begin();
        ans = max(ans, x * levels);
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