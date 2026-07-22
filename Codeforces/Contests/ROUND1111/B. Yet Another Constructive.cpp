#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k, m; cin >> n >> k >> m;

    if (k > m) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (i % k == 0) cout << (m - k) % m + 1 << ' ';
        else cout << 1 << ' ';
    }
    cout << '\n';
    // smallest length of subarray that is divisible by m is k
    // prefix sum (mod m) must be equal
    // just make all of them
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
