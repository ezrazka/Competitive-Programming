#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"
 
void solve(){
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
 
    vector<int> z(m);
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < m; i++){
        z[i] = max(0ll, min(z[i - l], r - i));
        while (i + z[i] < m && t[z[i]] == t[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i, r = i + z[i];
        }
    }
 
    int ans = 0;
    for (int i = 0, l = 0, r = 0; i < n; i++){
        int cur_z = max(0ll, min(z[i - l], r - i));
        while (i + cur_z < n && cur_z < m && t[cur_z] == s[i + cur_z]){
            cur_z++;
        }
        if (cur_z == m){
            ans++;
        }
        if (i + cur_z > r){
            l = i, r = i + cur_z;
        }
    }
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}