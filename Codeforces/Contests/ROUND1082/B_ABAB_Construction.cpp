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
        if (s[0] == 'b'){
            cout << "NO\n";
            return;
        }
        s = s.substr(1);
        n--;
    }


    for (int i = 0; i < n - 1; i += 2){
        if (s[i] == '?' && s[i + 1] == '?'){
            s[i] = 'a';
            s[i + 1] = 'b';
        } else if (s[i] == '?'){
            s[i] = 'a' + 'b' - s[i + 1];
        } else if (s[i + 1] == '?'){
            s[i + 1] = 'a' + 'b' - s[i];
        } else if (s[i] == s[i + 1]){
            cout << "NO\n";
            return;
        }
    }
    cout << (count(s.begin(), s.end(), 'a') == n / 2 ? "YES\n" : "NO\n");
    /*
    n odd -> s[0] == 'a'
    n even -> free, 

    abab

    abab
    abba
    baab
    baba

    ababab


    ababa

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