#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;

    vector<int> vans;
    if (n % 2 == 1) {
        vans = {1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3};
        for (int i = 4; i <= n; i++) vans.push_back(i);
        for (int i = n; i >= 4; i--) vans.push_back(i);
        for (int i = 4; i <= n; i++) vans.push_back(i);
        for (int i = 4; i <= n; i++) vans.push_back(i);
    } else {
        for (int i = 1; i <= n; i++) vans.push_back(i);
        for (int i = n; i >= 1; i--) vans.push_back(i);
        for (int i = 1; i <= n; i++) vans.push_back(i);
        for (int i = 1; i <= n; i++) vans.push_back(i);
    }

    for (int i = 0; i < 4 * n; i++) {
        cout << vans[i] << " \n"[i == 4 * n - 1];
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
