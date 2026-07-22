#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
    if (n <= 3) cout << 1 << '\n';
    else cout << min(abs(x2 - x1), (n - abs(x2 - x1)) % n) + k << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
