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

    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < n; i++){
        cnt += (s[i] == '(' ? 1 : -1);
        if (i < n - 1 && cnt == 0) ok = true;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}