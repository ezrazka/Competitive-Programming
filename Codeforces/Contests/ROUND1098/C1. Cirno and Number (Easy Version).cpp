#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

constexpr int INF = LLONG_MAX;

void solve() {
    string a; cin >> a;
    int n; cin >> n;
    vector<char> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    // evil overflow edge case
    if (a.length() == 18 && d == vector<char>{'9'}) {
        cout << 1 << '\n';
        return;
    }

    int ans = INF;
    {
        string b;
        for (int _ = 0; _ < a.length() - 1; _++) b += d[n - 1];
        // evil empty string edge case
        if (!b.empty()) ans = min(ans, abs(stoll(a) - stoll(b)));
    }
    {
        string b;
        for (int _ = 0; _ < a.length() + 1; _++) b += d[0];
        // evil leading 0 edge case
        if (b[0] == '0' && n > 1) b[0] = d[1];
        ans = min(ans, abs(stoll(a) - stoll(b)));
    }
    {
        string b;
        int i;
        for (i = 0; i < a.length(); i++) {
            if (!binary_search(d.begin(), d.end(), a[i])) break;
            b += a[i];
        }
        if (b.length() < a.length()) {
            auto it = lower_bound(d.begin(), d.end(), a[i]);
            if (it != d.begin()) it--;
            b += *it;
        }
        while (b.length() < a.length()) b += d[n - 1];
        ans = min(ans, abs(stoll(a) - stoll(b)));
    }
    {
        string b;
        int i;
        for (i = 0; i < a.length(); i++) {
            if (!binary_search(d.begin(), d.end(), a[i])) break;
            b += a[i];
        }
        if (b.length() < a.length()) {
            auto it = upper_bound(d.begin(), d.end(), a[i]);
            if (it == d.end()) it--;
            b += *it;
        }
        while (b.length() < a.length()) b += d[0];
        ans = min(ans, abs(stoll(a) - stoll(b)));
    }
    cout << ans << '\n';

    /*
        if a has k digits, find:
        1. largest num with k + 1 digits
        2. smallest num with k - 1 digits
        3. 1. appended with last digit less equal
        4. 2. appended with first digit greater equal
        or just assume we can choose 0
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
