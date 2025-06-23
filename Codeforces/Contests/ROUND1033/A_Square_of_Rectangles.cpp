#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

    int biggest = max({a, b, c, d, e, f});
    if (biggest == a || biggest == c || biggest == e){
        swap(a, b);
        swap(c, d);
        swap(e, f);
    }

    if (biggest == d){
        swap(a, c);
        swap(b, d);
    }
    if (biggest == f){
        swap(a, e);
        swap(b, f);
    }
    // cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';

    int need1 = biggest, need2 = biggest - a;
    if (
        // c == e && c == need1 && d + f == need2 ||
        c == e && c == need2 && d + f == need1 ||
        d == f && d == need1 && c + e == need2 
        // d == f && d == need2 && c + e == need1
    ){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}