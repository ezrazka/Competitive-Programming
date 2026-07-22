
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int msb(int n) {
    if (n == 0) return 0;
    return 1 << __lg(n);
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    stable_sort(ord.begin(), ord.end(), [&](int i, int j){
        return a[i] < a[j];
    });

    int mx = 0;
    for (int i = 0; i < n; i++) {
        // pair from and to, then find the largest threshold it must pass
        int from = i;
        int to = ord[i];
        mx = max(mx, msb(from ^ to));
    }
    cout << mx << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
