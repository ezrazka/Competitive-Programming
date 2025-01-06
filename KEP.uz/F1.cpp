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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<int> pref(n + 1), pref2(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + v[i];
        pref2[i] = pref2[i - 1] + i * v[i];
    }
    vector<int> suff(n + 1), suff2(n + 1);
    for (int i = 1; i <= n; i++){
        suff[i] = suff[i - 1] + v[n - i + 1];
        suff2[i] = suff2[i - 1] + i * v[n - i + 1];
    }

    int q; cin >> q;
    while (q--){
        int k; cin >> k;
        k = min(k, n - k + 1);
        int ans = pref2[k - 1] + k * (pref[n - k + 1] - pref[k - 1]) + suff2[k - 1];
        cout << ans << '\n';
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