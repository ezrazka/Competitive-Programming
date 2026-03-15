#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int sum = 0;
    for (char c : s){
        sum += c - '0';
    }
    s[0]--;
    sort(s.rbegin(), s.rend());

    int ans = 0;
    for (char c : s){
        if (sum < 10) break;
        sum -= c - '0';
        ans++;
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