#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int mx = 0;
    for (int i = 0; i < n; i++){
        mx += (s[i] == '1');
        if (1 <= i && i <= n - 2 && s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1') mx++, s[i] = '1';
    }
    int mn = 0;
    for (int i = 0; i < n; i++){
        mn += (s[i] == '1');
        if (1 <= i && i <= n - 2 && s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1') mn--, s[i] = '0';
    }
    cout << mn << ' ' << mx << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}