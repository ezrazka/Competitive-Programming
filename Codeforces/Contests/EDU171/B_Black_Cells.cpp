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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    if (!(n & 1)){
        int ans = 0;
        for (int i = 1; i < n; i += 2){
            ans = max(ans, v[i] - v[i - 1]);
        }
        cout << ans << '\n';
    } else {
        vector<int> pref(n + 1);
        for (int i = 2; i <= n; i += 2){
            pref[i] = max(pref[i - 2], v[i - 1] - v[i - 2]);
        }
        reverse(v.begin(), v.end());
        vector<int> suff(n + 1);
        for (int i = 2; i <= n; i += 2){
            suff[i] = max(suff[i - 2], v[i - 2] - v[i - 1]);
        }

        int ans = 1e18;
        for (int i = 0; i < n; i += 2){
            ans = min(ans, max(pref[i], suff[n + 1 - (i + 2)]));
        }
        cout << max(ans, 1ll) << '\n';
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