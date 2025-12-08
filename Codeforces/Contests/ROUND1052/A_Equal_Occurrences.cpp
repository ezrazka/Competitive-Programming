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
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }

    int ans = 1e18;
    for (int len = 1; len <= n; len++){
        int cur = 0;
        for (auto [key, val] : mp){
            if (val >= len) cur += val - len;
            else cur += val;
        }
        ans = min(ans, cur);
    }
    cout << n - ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}