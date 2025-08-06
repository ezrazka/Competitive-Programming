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

    bool ok = true;
    for (int i = 0; i < n - 1; i++){
        if (v[i] == 1 && v[i + 1] == 2){
            ok = false;
        }
    }

    int mn = v[0];
    for (int i = 1; i < n; i++){
        if (v[i] >= 2 * mn){
            ok = false;
        }
        mn = min(mn, v[i]);
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