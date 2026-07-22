#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](int a, int b) { return (a % 6 == 0) > (b % 6 == 0); });
    for (int i = 0; i < n; i++) {
        if (a[i] % 6 != 0) {
            sort(a.begin() + i, a.end(), [&](int a, int b) { return (a % 2 == 0) > (b % 2 == 0); });
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            sort(a.begin() + i, a.end(), [&](int a, int b) { return (a % 3 == 0) < (b % 3 == 0); });
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
