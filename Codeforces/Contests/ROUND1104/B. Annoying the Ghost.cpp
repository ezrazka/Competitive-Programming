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

    {
        auto temp = a;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            if (temp[i] > b[i]) {
                cout << "-1\n";
                return;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            int k = -1;
            for (int j = i; j < n; j++) {
                if (a[j] <= b[i]) {
                    k = j;
                    break;
                }
            }
            for (int j = k; j >= i + 1; j--) {
                swap(a[j - 1], a[j]);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    /* minimum number of operation 2s to make all a[i] <= b[i] */
    // 3 2 1
    // 2 2 3
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
