#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int idx1 = find(a.begin(), a.end(), 0) - a.begin();
    int idx2 = (n - 1) - (find(a.rbegin(), a.rend(), 0) - a.rbegin());

    auto find_mex = [&](int l, int r) -> int {
        vector<bool> vis(n / 2);
        for (int i = l; i <= r; i++) {
            vis[a[i]] = true;
        }
        return find(vis.begin(), vis.end(), false) - vis.begin();
    };

    int ans = 0;
    {
        int len = 0;
        while (0 <= idx1 - len && idx1 + len < n && a[idx1 - len] == a[idx1 + len]) len++;
        len--;
        ans = max(ans, find_mex(idx1 - len, idx1 + len));
    }
    {
        int len = 0;
        while (0 <= idx2 - len && idx2 + len < n && a[idx2 - len] == a[idx2 + len]) len++;
        len--;
        ans = max(ans, find_mex(idx2 - len, idx2 + len));
    }
    if ((idx1 + idx2) % 2 == 0) {
        int temp = (idx1 + idx2) / 2;
        int len = 0;
        while (0 <= temp - len && temp + len < n && a[temp - len] == a[temp + len]) len++;
        len--;
        ans = max(ans, find_mex(temp - len, temp + len));
    } else {
        int temp = (idx1 + idx2) / 2;
        int len = 0;
        while (0 <= temp - len && temp + len + 1 < n && a[temp - len] == a[temp + len + 1]) len++;
        len--;
        ans = max(ans, find_mex(temp - len, temp + len + 1));
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
