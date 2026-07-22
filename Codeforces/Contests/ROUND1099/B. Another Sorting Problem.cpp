#include <algorithm>
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

    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        k = max(k, a[i] - a[i + 1]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) a[i + 1] += k;
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
