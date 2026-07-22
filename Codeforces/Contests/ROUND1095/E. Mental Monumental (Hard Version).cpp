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

    map<int, int> freq;
    for (int i = 0; i < n; i++) freq[a[i]]++;

    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<bool> vis(n + 1);
        vector<int> b;
        map<int, int> cur_freq = freq;
        for (auto &[key, val] : cur_freq) {
            if (key < mid) {
                vis[key] = true;
                val--;
            }
            while (val--) {
                b.push_back(key);
            }
        }

        int res = 0;
        while (vis[res]) res++;
        for (int i = 0; i < b.size(); i++) {
            if (res < (b[i] + 1) / 2) res++;
            while (vis[res]) res++;
        }

        if (res >= mid) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
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
