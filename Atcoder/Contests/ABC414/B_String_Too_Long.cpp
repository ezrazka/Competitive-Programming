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
    vector<pair<char, int>> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
        sum += v[i].se;
        if (sum > 100){
            cout << "Too Long\n";
            return;
        }
    }

    for (int i = 0; i < n; i++){
        while (v[i].se--){
            cout << v[i].fi;
        }
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