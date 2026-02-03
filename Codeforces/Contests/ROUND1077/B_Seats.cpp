#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    string t = s;

    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            if (i - 1 >= 0) t[i - 1] = '1';
            if (i + 1 < n) t[i + 1] = '1';
        }
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (t[i] == '0'){
            cnt++;
        } else {
            ans += (cnt + 2) / 3;
            cnt = 0;
        }
    }
    ans += (cnt + 2) / 3;

    cout << count(s.begin(), s.end(), '1') + ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}