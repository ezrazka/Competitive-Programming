#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

int query(char c, int x) {
    cout << c << ' ' << x << endl;
    int q; cin >> q;
    return q;
}

void answer(int k, int c) {
    cout << "A " << k << ' ' << c << endl;
}

void solve() {
    int n; cin >> n;
    cout << 0 << endl;

    bool is_and = (query('I', 0) == 1);
    if (is_and) {
        int k = 1, c = 0, sz = 1;
        for (int bit = 0; bit < n; bit++) {
            if (query('I', 1ll << bit) == sz + 1) c |= (1ll << bit), sz++;
        }
        answer(k, c);
    } else {
        int l = 1, r = (1ll << n) - 1, c = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (query('Q', mid) == 1) {
                l = mid + 1;
                c = mid;
            } else {
                r = mid - 1;
            }
        }

        bool is_or;
        if (__builtin_popcountll(c) == 1) {
            query('I', (c == 1 ? 2 : 1));
            is_or = (query('I', c | (c == 1 ? 2 : 1)) == 3);
        } else {
            is_or = (query('I', c & -c) == 2);
        }
        int k = (is_or ? 2 : 3);
        answer(k, c);
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

