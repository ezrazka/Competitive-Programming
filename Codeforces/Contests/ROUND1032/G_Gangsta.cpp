#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + (s[i - 1] == '1' ? 1 : -1);
    }
    sort(pref.begin(), pref.end());

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += i * (n - i + 1);
    }
    for (int i = 0; i <= n; i++){
        ans += pref[i] * (i - (n - i));
    }
    ans /= 2;
    cout << ans << '\n';

    /*
    1. How does it work?
        * Utilize the fact that max(c0, c1) = (c0 + c1 + |c0 - c1|) / 2
        * Uses array sort trick to get absolute sum of all element pair differences
    2. How could I have come up with it myself?
        * Notice that max(c0, c1) = (c0 + c1 + |c0 - c1|) / 2
        * Notice that using a prefix sum + absolute pair difference trick works
    3. What can I do to make sure I can come up with it next time it appears?
        * remember formula trick
        * remember absolute pair difference trick
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}