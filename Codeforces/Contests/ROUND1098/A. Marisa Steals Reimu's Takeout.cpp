#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> freq(3);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    cout << freq[0] + min(freq[1], freq[2]) + abs(freq[1] - freq[2]) / 3 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
