#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;

    int x = s.length();
    string t;
    for (int i = 0; i <= x; i++){
        t += '9';
    }
    cout << stoi(t) - stoi(s) << '\n';
    /*
    a + b | ((a + b) + (99a)) 
    a + b must be equal to 99a
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