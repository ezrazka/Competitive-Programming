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
    string s, t; cin >> s >> t;
    vector<int> pref(n + 1);
    for (int i = 0; i < m; i++){
        int l, r; cin >> l >> r; l--, r--;
        pref[l]++;
        pref[r + 1]--;
    }
    for (int i = 1; i < n; i++){
        pref[i] += pref[i - 1];
    }
    for (int i = 0; i < n; i++){
        cout << (pref[i] & 1 ? t[i] : s[i]);
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}