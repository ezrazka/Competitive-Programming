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
    vector<pii> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }

    vector<int> bad(2 * n + 1);
    for (int i = 0; i < n; i++){
        if (v[i].fi == v[i].se){
            bad[v[i].fi]++;
        }
    }
    vector<int> pref(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++){
        pref[i] = pref[i - 1] + !!bad[i];
    }

    for (int i = 0; i < n; i++){
        if (v[i].fi == v[i].se){
            cout << (bad[v[i].fi] == 1);
        } else {
            cout << (pref[v[i].se] - pref[v[i].fi - 1] < v[i].se - v[i].fi + 1);
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}