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
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    int ans = 0;

    int cnt0 = mp[0];
    ans += cnt0;
    mp[0] -= cnt0;
    
    for (auto [key, val] : mp){
        ans += key * val;
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