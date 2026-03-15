#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;

    if (multiset(s.begin(), s.end()) != multiset(t.begin(), t.end())){
        cout << "-1\n";
        return;
    }

    int ans = n;
    for (int k = 0; k < n; k++){
        string u = t.substr(k);
        int i = 0, j = 0;
        while (i < s.length() && j < u.length()){
            if (s[i] == u[j]) i++, j++;
            else i++;
        }
        ans = min(ans, n - j);
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