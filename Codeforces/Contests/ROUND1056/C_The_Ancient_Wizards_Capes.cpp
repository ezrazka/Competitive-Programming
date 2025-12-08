#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;
    for (int start = 0; start <= 1; start++){
        bool ok = true;
        vector<int> dir(n);
        dir[0] = start;
        for (int i = 1; i < n; i++){
            int diff = abs(v[i] - v[i - 1]);
            if (diff == 1){
                dir[i] = dir[i - 1];
            } else if (diff == 0){
                dir[i] = !dir[i - 1];
            } else {
                ok = false;
                break;
            }
        }
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++){
            pref[i] = pref[i - 1] + dir[i - 1];
        }
        for (int i = 1; i <= n; i++){
            if (((i - 1) - (pref[i - 1] - pref[0])) + (pref[n] - pref[i]) + 1 != v[i - 1]){
                ok = false;
                break;
            }
        }
        if (ok) ans++;
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