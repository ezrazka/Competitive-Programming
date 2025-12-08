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
    int n = s.length();

    for (int i = 0; i < n - 1; i++){
        if (
            s[i] == '*' && s[i + 1] == '*' ||
            s[i] == '>' && s[i + 1] == '*' ||
            s[i] == '*' && s[i + 1] == '<' ||
            s[i] == '>' && s[i + 1] == '<'
        ){
            cout << "-1\n";
            return;
        }
    }

    int ans = 0;
    {
        int cur = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '>'){
                break;
            }
            cur++;
        }
        ans = max(ans, cur);
    }
    {
        int cur = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == '<'){
                break;
            }
            cur++;
        }
        ans = max(ans, cur);
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