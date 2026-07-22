#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

void solve(){
    int a, b, c, m; cin >> a >> b >> c >> m;
    int ca = 6 * (m / a) - 3 * (m / lcm(a, b) + m / lcm(a, c) - m / lcm(lcm(a, b), c)) - 1 * (m / lcm(lcm(a, b), c));
    int cb = 6 * (m / b) - 3 * (m / lcm(a, b) + m / lcm(b, c) - m / lcm(lcm(a, b), c)) - 1 * (m / lcm(lcm(a, b), c));
    int cc = 6 * (m / c) - 3 * (m / lcm(a, c) + m / lcm(b, c) - m / lcm(lcm(a, b), c)) - 1 * (m / lcm(lcm(a, b), c));
    cout << ca << ' ' << cb << ' ' << cc << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
