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
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> pref(n + 2, 0);
    for (int i = 0; i < n; i++){
        pref[1]++, pref[a[i] / 4 + 1]--;
        for (int x = 1; x * x <= a[i]; x++){
            if (a[i] % x == 0){
                if (x > a[i] / 4) pref[x]++, pref[x + 1]--;
                if (a[i] / x > a[i] / 4 && x != a[i] / x) pref[a[i] / x]++, pref[a[i] / x + 1]--;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        pref[i] += pref[i - 1];
        if (n - pref[i] <= k) ans = max(ans, i);
    }
    cout << ans << '\n';

    /*
        a[i] can form gcds {all of its factors} union {1..a[i] / 4}
        we can delete up to k items
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