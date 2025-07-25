#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a % 2 == 1 && a - 1 == b){
        cout << y << '\n';
    } else if (a > b){
        cout << -1 << '\n';
    } else {
        int evens = (b - a + (a % 2 == 0)) / 2;
        int odds = (b - a) - evens;
        cout << odds * x + evens * min(x, y) << '\n';
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