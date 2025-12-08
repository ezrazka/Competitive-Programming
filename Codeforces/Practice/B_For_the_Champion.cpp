#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(char c, int k){
    cout << "? " << c << ' ' << k << endl;
    int res; cin >> res;
    return res;
}

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }

    query('U', 1e9);
    query('U', 1e9);
    query('L', 1e9);
    int topleft = query('L', 1e9);
    // = min((v[i].fi - (a - 2e9)) + ((b + 2e9) - v[i].se))
    // = min(v[i].fi - v[i].se) - a + b + 4e9
    // a - b = min(v[i].fi - v[i].se) + 4e9 - topleft
    query('R', 1e9);
    query('R', 1e9);
    query('R', 1e9);
    int topright = query('R', 1e9);
    // = min(((a + 2e9) - v[i].fi) + ((b + 2e9) - v[i].se))
    // = min(-v[i].fi - v[i].se) + a + b + 4e9
    // -a - b = min(-v[i].fi - v[i].se) + 4e9 - topright

    int min1 = 1e18, min2 = 1e18;
    for (int i = 0; i < n; i++){
        min1 = min(min1, v[i].fi - v[i].se);
        min2 = min(min2, -v[i].fi - v[i].se);
    }

    int a_min_b = min1 + 4e9 - topleft;
    int min_a_min_b = min2 + 4e9 - topright;
    int a = (a_min_b - min_a_min_b) / 2;
    int b = a - a_min_b;
    cout << "! " << a << ' ' << b << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}