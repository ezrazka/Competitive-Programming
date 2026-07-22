#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for (int i = 0; i < n - k; i++) {
        if (s[i] == '1') s[i] ^= 1, s[i + k] ^= 1;
    }
    cout << (s == string(n, '0') ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
