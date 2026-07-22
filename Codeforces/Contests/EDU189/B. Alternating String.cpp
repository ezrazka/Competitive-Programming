#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    string s; cin >> s;
    int n = s.length();

    int same = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            same++;
        }
    }

    cout << (same <= 2 ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
