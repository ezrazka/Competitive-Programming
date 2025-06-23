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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    int ans = 0;
    map<int, int> mp;
    int last = 0;
    for (int i = 1; i <= n; i++){
        if (mp[v[i]] != 0){
            last = max(last, mp[v[i]]);
        }
        ans += i - last;
        mp[v[i]] = i;
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