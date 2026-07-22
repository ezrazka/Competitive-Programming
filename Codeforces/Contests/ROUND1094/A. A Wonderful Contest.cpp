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

    vector<bool> dp(101);
    dp[0] = true;
    for (int x : a) {
        for (int i = 100 / x; i <= 100; i++) {
            dp[i] = dp[i] || dp[i - 100 / x];
        }
    }

    cout << (accumulate(dp.begin(), dp.end(), 0) == 101 ? "Yes\n" : "No\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
