#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int n = s.length();

    if (s.length() >= 2 && s[n - 2] == 'u' && s[n - 1] == 's'){
        cout << s.substr(0, n - 2) << 'i' << '\n';
    } else {
        cout << s << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}