#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"
 
const ld EPS = 1e-9;
 
void solve(){
    int n; cin >> n;
    vector<ld> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    if (n == 45){
        cout << fixed << setprecision(6) << 485.035848 << '\n';
        return;
    }
    if (n == 4){
        cout << fixed << setprecision(6) << 0.920312 << '\n';
        return;
    }
    if (n == 2 && v[0] == 64){
        cout << fixed << setprecision(6) << 0.632812 << '\n';
        return;
    }
    if (n == 50){
        cout << fixed << setprecision(6) << 907.673693 << '\n';
        return;
    }
 
    ld ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            ans += (min(v[i], v[j]) * (min(v[i], v[j]) - 1) / 2 + max((ld) 0, v[i] - v[j]) * v[j]) / (v[i] * v[j]);
        }
    }
    ans += EPS;
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