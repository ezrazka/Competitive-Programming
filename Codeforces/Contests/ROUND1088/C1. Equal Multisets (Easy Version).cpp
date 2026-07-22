#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    {
        vector<int> freq(n + 1);
        for (int i = 0; i < n; i++) if (b[i] != -1) freq[b[i]]++;
        for (int i = 0; i <= n; i++) if (freq[i] > 1) return cout << "NO\n", void();
    }
    {
        vector<bool> vis(n + 1);
        for (int i = 0; i < n; i++) if (b[i] != -1) vis[b[i]] = true;

        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && vis[a[j]]) j++;
            if (b[i] != -1) continue;
            b[i] = a[j];
            j++;
        }
    }
    {
        bool ok = true;
        for (int i = 0; i < n - k; i++) {
            if (a[i] != b[i] || a[(n - 1) - i] != b[(n - 1) - i]) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
