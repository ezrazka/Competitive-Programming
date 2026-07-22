#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int median;
    {
        vector<int> temp = a;
        sort(temp.begin() + 1, temp.end());
        median = temp[(n + 1) / 2];
    }

    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int less = 0, equal = 0;
        for (int j = i; j >= 1; j--) {
            less += (a[j] < median);
            equal += (a[j] == median);
            if ((j - i) & 1) continue;
            bool is_median = (
                less < ((i - j + 1) + 1) / 2 &&
                less + equal >= ((i - j + 1) + 1) / 2
            );
            if (is_median) dp[i] = max(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
