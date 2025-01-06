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

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + v[i - 1];
    }

    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r; l--, r--;
        cout << pref[r + 1] - pref[l] << '\n';
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