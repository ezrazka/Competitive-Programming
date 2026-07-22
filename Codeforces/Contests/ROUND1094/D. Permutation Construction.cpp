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

    for (int i = n - 2; i >= 0; i--) {
        a[i] += a[i + 1];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<int> vans(n);
    for (int i = 0; i < n; i++) {
        vans[ord[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << vans[i] + 1 << " \n"[i == n - 1];
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
