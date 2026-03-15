#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    if (n & 1){
        cout << "NO\n";
        return;
    }

    for (int _ = 0; _ < n / 2; _++){
        string t;
        for (int i = 0; i < s.length(); i++){
            if (i + 1 < s.length() && s[i] == s[i + 1]) i++;
            else t += s[i];
        }
        if (t.length() == 0){
            cout << "YES\n";
            return;
        }
        s = t;
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}