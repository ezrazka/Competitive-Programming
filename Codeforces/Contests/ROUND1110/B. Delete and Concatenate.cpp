#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

const int INF = 1e18;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= c;
        cout << a[i] << " \n"[i == n - 1];
    }

    int ans = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!st.empty() && (st.top() < 0 != a[i] < 0)) {
            ans += max(st.top(), a[i]);
            st.pop();
        } else {
            st.push(a[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
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
