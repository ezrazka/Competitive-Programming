#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int lcm(int x, int y){
    return x * y / __gcd(x, y);
}

void solve(){
    int n; cin >> n;
    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        v[i] = lcm(p[i], s[i]);
    }

    bool ok = true;
    int pref = 0;
    for (int i = 0; i < n; i++){
        pref = __gcd(pref, v[i]);
        if (pref != p[i]) ok = false;
    }
    int suff = 0;
    for (int i = n - 1; i >= 0; i--){
        suff = __gcd(suff, v[i]);
        if (suff != s[i]) ok = false;
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