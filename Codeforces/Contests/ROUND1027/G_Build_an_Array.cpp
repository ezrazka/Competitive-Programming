#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 2; i <= n; i++){
        pref[i] = pref[i - 1] + (v[i] & -v[i]);
        if (v[i] % v[i - 1] == 0 && __builtin_popcount(v[i] / v[i - 1]) == 1){
            pref[i] -= (v[i - 1] & -v[i - 1]) * 2 - 1;
        }
    }
    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 1; i--){
        suff[i] = suff[i + 1] + (v[i] & -v[i]);
        if (v[i] % v[i + 1] == 0 && __builtin_popcount(v[i] / v[i + 1]) == 1){
            suff[i] -= (v[i + 1] & -v[i + 1]) * 2 - 1;
        }
    }

    bool ok = false;
    for (int i = 1; i <= n; i++){
        if (pref[n] - pref[i] + suff[1] - suff[i] + (v[i] & -v[i]) >= k){
            ok = true;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}