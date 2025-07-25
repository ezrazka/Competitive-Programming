#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, k; cin >> a >> b >> k;
    if (a > b) swap(a, b);
    int gcd = __gcd(a, b);
    a /= gcd, b /= gcd;
    cout << (b <= k ? 1 : 2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}