#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int k; cin >> k;
    string s, t; cin >> s >> t;
    if (s.length() > t.length()) swap(s, t);
    int n = s.length();
    int m = t.length();

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m; j++){
        while (i < n && j < m && s[i] == t[j]){
            ans++;
            i++, j++;
        }
    }

    int diff = 0;
    for (int i = 0; i < n; i++){
        diff += s[i] != t[i];
    }

    if (ans >= max(n, m) - 1 || diff == 1 && n == m){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}