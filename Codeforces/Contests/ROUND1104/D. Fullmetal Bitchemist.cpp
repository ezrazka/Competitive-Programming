#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && s[st.top()] == s[i]) {
            st.pop();
            s[i] ^= 1;
        }
        ans += i - (st.empty() ? -1 : st.top());
        // debug(ans);
        st.push(i);
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
