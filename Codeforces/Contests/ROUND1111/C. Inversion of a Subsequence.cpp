#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (accumulate(a.begin(), a.end(), 0) != n && accumulate(b.begin(), b.end(), 0) == n) {
        cout << -1 << '\n';
        return;
    }

    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    
    if (accumulate(a.begin(), a.end(), 0) == 0) {
        cout << -1 << '\n';
        return;
    }

    {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (a[i] == 1 && b[i] == 0);
        }
        cout << (cnt & 1 ? 1 : 2) << '\n';
    }

    // the number of ones can only reach up to n-1`
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
