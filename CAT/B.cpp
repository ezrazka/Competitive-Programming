#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, t; cin >> n >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    int ans1 = 0, ans2 = 0;
    {
        int temp = t;
        if (temp >= a[0].first) temp -= a[0].first, ans1++;
        ans1 += temp / (a[0].first + a[0].second);
    }
    if (n > 1){
        int temp = t;
        ans2 += 2 * (temp / (a[0].first + a[1].first));
        temp %= (a[0].first + a[1].first);
        if (temp >= a[0].first) temp -= a[0].first, ans2++;
    }

    cout << max(ans1, ans2) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
