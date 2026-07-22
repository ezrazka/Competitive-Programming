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

    vector<int> next_a(n, n);
    {
        map<int, int> mp_a;
        for (int i = n - 1; i >= 0; i--) {
            if (mp_a.find(a[i] + 1) != mp_a.end()) {
                next_a[i] = mp_a[a[i] + 1];
            }
            mp_a[a[i]] = i;
        }
    }
    vector<int> next_b(n, n);
    {
        map<int, int> mp_b;
        for (int i = n - 1; i >= 0; i--) {
            if (mp_b.find(b[i] + 1) != mp_b.end()) {
                next_b[i] = mp_b[b[i] + 1];
            }
            mp_b[b[i]] = i;
        }
    }

    int m = __lg(n);
    vector<vector<int>> up(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < n; i++) {
        up[i][0] = (next_a[i] == next_b[i] ? next_a[i] : -1);
    }
    for (int bit = 1; bit <= m; bit++) {
        for (int i = 0; i < n; i++) {
            if (up[i][bit - 1] == -1) continue;
            if (up[i][bit - 1] == n) { up[i][bit] = n; continue; }
            up[i][bit] = up[up[i][bit - 1]][bit - 1];
        }
    }

    vector<int> next_1(n, n);
    {
        int idx = n;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 1 || b[i] == 1) idx = i;
            next_1[i] = idx;
        }
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        int r = next_1[l];
        if (a[r] == 1 && b[r] == 1) {
            for (int bit = m; bit >= 0; bit--) {
                if (up[r][bit] != -1) r = up[r][bit];
            }
            if (r < n) r++;
        }
        ans += (r - l);
    }
    cout << ans << '\n';

    /*
        count how many subarrays A[L..R] exist such that:
        for all prefixes of A[L..R], Alice's and Bob's MEXes are equal

        nvm its not a MEX problem because they can only watch one episode.

        try using binary lifting?
        if Alice takes take a[i] and Bob takes b[i], then check if its the same as Bob's,
        with a precomputed sparse table, the will take logN per L fixing

        1. for each i, find the first j where a[j] = a[i] + 1, stored in vector
        2. sparse_table[i][bit] = whether you can go forward (1 << bit) times
        3. for each index, just binary lift to check
    */
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
