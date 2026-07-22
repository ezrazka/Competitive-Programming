#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    ld favorable_ways = 0;
    {
        vector<int> sum(26);
        for (int i = 0; i < n; i++) {
            sum[b[i] - 'A'] += i + 1;
            favorable_ways += sum[a[i] - 'A'] * (n - i);
        }
    }
    {
        vector<int> sum(26);
        for (int i = n - 1; i >= 0; i--) {
            favorable_ways += sum[a[i] - 'A'] * (i + 1);
            sum[b[i] - 'A'] += n - i;
        }
    }

    int total_ways = n * (n + 1) * (2 * n + 1) / 6;
    ld ans = favorable_ways / total_ways;
    cout << fixed << setprecision(9) << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
