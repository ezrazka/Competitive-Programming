#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        freq[v[i]]++;
    }

    int ans = 1;
    for (auto [x, y] : freq){
        ans = (ans * (y + 1)) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
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