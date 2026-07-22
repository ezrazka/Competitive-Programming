#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    vector<string> ans {
        "",
        "walk",
        "no",
        "no",
        "no",
        "yes",
        "yes",
        "backwards",
        "7"
    };
    int x; cin >> x;
    cout << ans[x];
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
