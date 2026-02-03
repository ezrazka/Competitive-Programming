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
    
    auto rec = [&](auto self, int n) -> int {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int msb = 63 - __builtin_clzll(n);
        int msb_pow = 1ll << msb;
        return msb * (1ll << msb - 1) + self(self, n - msb_pow) + (n - msb_pow + 1);
    };
    cout << rec(rec, n) << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}