#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b; cin >> a >> b;
    string s = to_string(a), t = to_string(b);

    int ans = 0;
    int i = 0;
    bool one = false;
    for (; i < s.length(); i++){
        if (one){
            if (s[i] == '9' && t[i] == '0') ans += 1;
            else break;
        } else {
            if (s[i] == t[i]) ans += 2;
            else if (!one && (t[i] - s[i] + 10) % 10 == 1) ans += 1, one = true;
            else break;
        }
    }
    cout << ans << '\n';

    // 79
    // 68

    // 77
    // 69

    // 10
    // 09
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}