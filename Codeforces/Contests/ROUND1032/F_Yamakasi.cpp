#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, s, x; cin >> n >> s >> x;
    vector<int> v(n + 1); for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + v[i];
    }

    int ans = 0;
    map<int, int> mp;
    mp[0]++;
    bool found = false;
    int j = 1;
    for (int i = 1; i <= n; i++){
        if (v[i] > x){
            mp.clear();
            found = false;
            j = i;
        } else {
            if (v[i] == x){
                found = true;
                while (j < i){
                    mp[pref[j++]]++;
                }
            }
            if (found){
                ans += mp[pref[i] - s];
            }
        }
        if (!found){
            mp[pref[j++]]++;
        }
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