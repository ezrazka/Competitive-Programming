#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
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

    { // coordinate compression, in case of TLE
        vector<int> v = a;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        }
    }

    vector<int> cnt(n), leftmost(n, -1), rightmost(n, -1);

    auto update = [&]() -> void {
        for (int i = 0; i < n; i++) cnt[a[i]] = 0;
        for (int i = 0; i < n; i++) leftmost[a[i]] = -1;
        for (int i = 0; i < n; i++) rightmost[a[i]] = -1;
        for (int i = 0; i < n; i++) cnt[a[i]]++;
        for (int i = n - 1; i >= 0; i--) leftmost[a[i]] = i;
        for (int i = 0; i < n; i++) rightmost[a[i]] = i;
    };

    auto count_bad = [&]() -> int {
        int bad = 0;
        for (int val = 0; val < n; val++) {
            if (leftmost[val] == -1) continue;
            if (rightmost[val] - leftmost[val] + 1 > cnt[val]) bad++;
        }
        return bad;
    };

    update();

    {
        if (count_bad() == 0) {
            cout << "YES\n";
            return;
        }
    }
    { // check if bad > 2
        if (count_bad() > 2) {
            cout << "NO\n";
            return;
        }
    }
    { // 6 cases
        int val;
        for (int i = 0; i < n; i++) {
            if (leftmost[val] == -1) continue;
            if (rightmost[i] - leftmost[i] + 1 > cnt[i]) {
                val = i;
                break;
            }
        }

        int first = leftmost[val];
        int last = rightmost[val];
        int before = (leftmost[val] - 1 < 0 ? -1 : leftmost[val] - 1);
        int after = (rightmost[val] + 1 >= n ? -1 : rightmost[val] + 1);
        int missing1 = leftmost[val];
        while (a[missing1] == val) missing1++;
        while (a[missing1] != val) missing1++; missing1--;
        int missing2 = rightmost[val];
        while (a[missing2] == val) missing2--;
        while (a[missing2] != val) missing2--; missing2++;
        vector<pair<int, int>> cases = {
            {first, missing1},
            {first, missing2},
            {first, after},
            {last, missing1},
            {last, missing2},
            {last, before},
        };
        for (auto [x, y] : cases) {
            if (x == -1 || y == -1) continue;
            swap(a[x], a[y]);
            update();
            if (count_bad() == 0) {
                cout << "YES\n";
                return;
            }
            swap(a[x], a[y]);
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
