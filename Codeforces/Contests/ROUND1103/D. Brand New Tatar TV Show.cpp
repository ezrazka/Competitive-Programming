#include <any>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    vector<bool> dp(n + 1);
    queue<int> q;
    for (int i : a) {
        while (!q.empty() && q.back() > i + k) q.pop();
        if (q.empty()) q.push(i), dp[i] = false;
        else {
            if (q.front() == i) q.pop();
            dp[i] = true;
        };
    }
    cout << (accumulate(dp.begin(), dp.end(), 0) ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
