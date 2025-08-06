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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int ans = 0;
    for (int median = 1; median <= min(n, 100ll); median++){
        vector<int> signs(n + 1);
        for (int i = 1; i <= n; i++){
            signs[i] = signs[i - 1] + (v[i] < median ? -1 : 1);
        }
        
        vector<int> pref = signs, suff = signs;
        for (int i = 1; i <= n; i++) pref[i] = min(pref[i], pref[i - 1]);
        for (int i = n - 1; i >= 1; i--) suff[i] = max(suff[i], suff[i + 1]);

        int mn = 1e18;
        for (int i = 1; i <= n; i++){
            if (pref[i - 1] <= suff[i]) mn = min(mn, v[i]);
        }
        ans = max(ans, median - mn);
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