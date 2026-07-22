#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, x, y, z; cin >> n >> x >> y >> z;
    int ans1 = 0;
    {
        int cnt = 0;
        while (cnt < n) {
            cnt += x + y;
            ans1++;
        }
    }
    int ans2 = 0;
    {
        int cnt = 0;
        while (cnt < n) {
            cnt += x;
            if (ans2 >= z) cnt += 10 * y;
            ans2++;
        }
    }
    cout << min(ans1, ans2) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
