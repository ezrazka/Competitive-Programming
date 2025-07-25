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

    int argmn = min_element(v.begin(), v.end()) - v.begin();
    int mn = *min_element(v.begin(), v.end());

    if (mn == 0){
        bool ok = (argmn == 0);
        for (int i = 0; i < n; i++){
            if (v[i] != __builtin_popcountll(i - argmn)){
                ok = false;
                break;
            }
        }
        cout << (ok ? 0 : -1) << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        v[i] -= mn - 1;
    }

    for (int bit = 0; bit <= 60; bit++){
        bool ok = true;
        for (int i = 0; i < n; i++){
            if (v[i] != __builtin_popcountll((1ll << bit) + (i - argmn))){
                ok = false;
                break;
            }
        }
        if (ok){
            int msb = 0;
            for (int i = 0; i < n; i++){
                msb = max(msb, __lg((1ll << bit) + (i - argmn)));
            }
            cout << ((1ll << bit) - argmn) + ((1ll << ((mn - 1) + msb + 1)) - 1) - ((1ll << (msb + 1)) - 1) << '\n';
            return;
        }
    }
    
    cout << -1 << '\n';
}
        
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}