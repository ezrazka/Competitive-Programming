#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < n; i++){
        if (string(s, i, min(n - i, 4ll)) == "2026"){
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++){
        if (string(s, i, min(n - i, 4ll)) == "2025"){
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}