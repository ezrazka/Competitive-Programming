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

    bool a = false, c = false, g = false, t = false;
    for (int i = 0; i < n; i++){
        if (a + c + g + t == 3){
            if (!a && s[i] == 'A') cout << 'A';
            else if (!c && s[i] == 'C') cout << 'C';
            else if (!g && s[i] == 'G') cout << 'G';
            else if (!t && s[i] == 'T') cout << 'T';
            else continue;
            a = false, c = false, g = false, t = false;
        } else {
            if (!a && s[i] == 'A') a = true;
            if (!c && s[i] == 'C') c = true;
            if (!g && s[i] == 'G') g = true;
            if (!t && s[i] == 'T') t = true;
        }
    }
    if (!a) cout << 'A';
    else if (!c) cout << 'C';
    else if (!g) cout << 'G';
    else if (!t) cout << 'T';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}