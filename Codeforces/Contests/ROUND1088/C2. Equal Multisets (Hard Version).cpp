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

    for (int j = 0; j < k; j++) {
        int bot = -1;
        for (int i = j; i < n; i += k) {
            if (b[i] != -1 && a[i] != b[i]) {
                bot = b[i];
                break;
            }
        }
        for (int i = j; i < n; i += k) {
            if (b[i] != -1) continue;
            b[i] = (bot == -1 ? a[i] : bot);
        }
    }

    bool ok = true;
    vector<int> freq(n + 1);
    for (int i = 0; i < k; i++) {
        freq[a[i]]++;
        if (b[i] != -1) freq[b[i]]--; 
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] < 0) ok = false;
    }
    for (int i = k; i < n; i++) {
        freq[a[i]]++;
        if (b[i] != -1) freq[b[i]]--; 
        freq[a[i - k]]--;
        if (b[i - k] != -1) freq[b[i - k]]++; 
        if (freq[a[i - k]] < 0) ok = false;
        if (freq[b[i]] < 0) ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
