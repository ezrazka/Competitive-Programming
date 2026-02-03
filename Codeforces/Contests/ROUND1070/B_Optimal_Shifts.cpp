#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    rotate(s.begin(), find(s.begin(), s.end(), '1'), s.end());

    int ans = 0;
    for (int i = 0, cnt = 0; i < n; i++){
        if (s[i] == '1') cnt = 0;
        else cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}