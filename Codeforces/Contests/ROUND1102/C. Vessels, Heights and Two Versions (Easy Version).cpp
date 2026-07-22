#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a.push_back(a[i]);
    for (int i = 0; i < n; i++) a.push_back(a[i]);

    vector<int> left(3 * n, -1);
    {
        stack<int> st;
        for (int i = 0; i < 3 * n; i++) {
            while (!st.empty() && a[(st.top() + (n - 1)) % n] < a[(i + (n - 1)) % n]) st.pop();
            if (!st.empty()) left[i] = (st.top() + (n - 1)) % n;
            st.push(i);
        }
    }
    vector<int> right(3 * n, 3 * n);
    {
        stack<int> st;
        for (int i = 3 * n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] < a[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }
    }

    vector<int> pref(3 * n);
    for (int i = 0; i < 3 * n - 1; i++) {
        pref[i + 1] = pref[i] + min(a[i], a[(i + (n - 1)) % n]);
    }

    for (int i = n; i < 2 * n; i++) {
        cout << left[i] % n << " \n"[i == 2 * n - 1];
    }
    for (int i = n; i < 2 * n; i++) {
        cout << right[i] % n << " \n"[i == 2 * n - 1];
    }
    for (int i = n; i < 2 * n; i++) {
        int l = left[i], r = right[i];
        if (l % n == r % n) cout << min(a[i - 1], a[i]) * (n - 1) << " \n"[i == 2 * n - 1];
        else {
            int sum = pref[n];
            int sub = (pref[(i - 1) + 1] - pref[l]) + (pref[r + 1] - pref[i + 1]);
            int add = a[i - 1] * (((i - l) % n + n) % n) + a[i] * (((r - i) % n + n) % n);
            int ans = sum - sub + add;
            cout << ans << " \n"[i == 2 * n - 1];
        }
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
