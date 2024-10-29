#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int zeros = count(s.begin(), s.end(), '0');
    int used_zeros = 0;

    int ans = 0;
    int last = 0;
    while (last < n && s[last] == '0') last++;
    int i = n - 1;
    for (; i > last; i--){
        if (s[i] == '0'){
            if (used_zeros){
                used_zeros--;
            } else {
                zeros--;
            }
        } else {
            if (zeros){
                zeros--;
                used_zeros++;
            } else {
                last++;
                while (last < i - 1 && s[last] == '0') last++;
            }
            ans += (i + 1);
        }
    }
    if (i == last && i > 0 && zeros) ans += i + 1;
    cout << n * (n + 1) / 2 - ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}