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

    vector<vector<int>> dp(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            if (l == r) {
                dp[l][r] = 1;
            } else {
                int merge_cost = 2 * (max(a[l], a[r]) % min(a[l], a[r]) != 0);
                dp[l][r] = (l + 1 == r ? merge_cost : dp[l + 1][r - 1] + merge_cost);
                for (int k = l; k < r - 1; k++) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }

    vector<int> vans;
    queue<pair<int, int>> q;
    q.emplace(0, n - 1);
    while (!q.empty()) {
        auto [l, r] = q.front(); q.pop();

        if (l == r) {
            vans.push_back(l);
            continue;
        }

        int merge_cost = 2 * (max(a[l], a[r]) % min(a[l], a[r]) != 0);
        if (dp[l][r] == (l + 1 == r ? merge_cost : dp[l + 1][r - 1] + merge_cost)) {
            if (l + 1 != r) {
                if (merge_cost == 2) {
                    vans.push_back(l);
                    vans.push_back(r);
                }
                q.emplace(l + 1, r - 1);
            }
            continue;
        }

        for (int k = l; k < r - 1; k++) {
            if (dp[l][r] == dp[l][k] + dp[k + 1][r]) {
                q.emplace(l, k);
                q.emplace(k + 1, r);
                break;
            }
        }
    }
    sort(vans.begin(), vans.end());

    cout << dp[0][n - 1] << '\n';
    for (int i = 0; i < vans.size(); i++) {
        cout << vans[i] + 1 << " \n"[i == n - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
