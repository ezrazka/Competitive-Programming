#include <algorithm>
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

    vector<map<int, int>> dp(n);
    vector<int> mx1(n, -1), mx2(n, -1), argmx(n, -1);
    for (int i = 0; i < n; i++){
        int x = (i - 1 < 0 ? 0 : __gcd(a[i - 1], a[i]));
        int y = (i >= n - 1 ? 0 : __gcd(a[i], a[i + 1]));
        if (x == 0) x = y;
        if (y == 0) y = x;

        int z = x * y / __gcd(x, y);
        {
            int temp = b[i] / z;
            for (int j = 2; j * j <= temp; j++) {
                if (temp % j == 0) {
                    while (temp % j == 0) {
                        temp /= j;
                    }
                    dp[i][j] = 0;
                }
            }
            dp[i][1] = 0;
            if (temp != 0) dp[i][temp] = 0;
        }

        if (i == 0) {
            for (auto [key, _] : dp[i]) {
                dp[i][key] = (key != a[i] / z);
            }
            continue;
        }

        vector<int> values;
        for (auto [key, _] : dp[i]) {
            if (key == 1 || key != argmx[i - 1]) {
                dp[i][key] = mx1[i - 1] + (key != a[i] / z);
            } else {
                dp[i][key] = mx2[i - 1] + (key != a[i] / z);

            }
            values.push_back(dp[i][key]);
        }

        sort(values.rbegin(), values.rend());
        mx1[i] = values[0];
        if (values.size() > 1) mx2[i] = values[1];
        for (auto [key, val] : dp[i]) {
            if (val == mx1[i]) {
                argmx[i] = key;
                break;
            }
        }
    }

    int ans = 0;
    for (auto [key, val] : dp[n - 1]) {
        ans = max(ans, val);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
