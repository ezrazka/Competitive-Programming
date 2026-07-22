#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n, q; cin >> n >> q;

    vector<int> cnt(n + 1), freq(q + 1);
    int offset = 0;

    for (int _ = 0; _ < q; _++) {
        int qq; cin >> qq;
        if (qq == 1) {
            int x; cin >> x;
            cnt[x]++, freq[cnt[x]]++;
            if (freq[cnt[x]] == n) offset++;
        } else {
            int y; cin >> y;
            cout << (y + offset > q ? 0 : freq[y + offset]) << '\n';
        }
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
