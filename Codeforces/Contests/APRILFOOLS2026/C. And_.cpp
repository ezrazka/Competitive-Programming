/*
𝚁𝚇𝙾𝙴𝙰𝚁𝙳𝙼𝚃𝙸𝙽𝙷𝚄𝚂𝙴𝚁𝙼𝙴𝙳𝙴𝚂𝙸𝙰𝙽𝚃
1001101010010011000110001
READTHEREST
XORMINUSMEDIAN
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int a, b, c; cin >> a >> b >> c;
    cout << (a ^ b ^ c) - (a + b + c - min({a, b, c}) - max({a, b, c})) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
