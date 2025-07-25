#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"
 
const ld EPS = 1e-17;
 
void solve(){
    int n; cin >> n;
    vector<ld> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    ld ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            ans += (min(v[i], v[j]) * (min(v[i], v[j]) - 1) / 2 + max((ld) 0, v[i] - v[j]) * v[j]) / (v[i] * v[j]);
        }
    }
    ostringstream oss;
    oss << fixed << setprecision(7) << ans;
    string s = oss.str();
    if (s.back() == '5'){
        ld rounded = stold(s);
        if (abs(ans - rounded) < EPS){
            if ((s[s.length() - 2] - '0') & 1){
                cout << fixed << setprecision(6) << ceil(ans * 1e6) / 1e6 << '\n';
            } else {
                cout << fixed << setprecision(6) << floor(ans * 1e6) / 1e6 << '\n';
            }
            return;
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}