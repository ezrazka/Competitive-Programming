#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (2 * k > n) {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) ans += (s[i] != 'R');
    for (int i = n - 1; i >= n - k; i--) ans += (s[i] != 'L');
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
