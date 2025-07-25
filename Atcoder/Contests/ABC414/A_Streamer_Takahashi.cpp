#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, l, r; cin >> n >> l >> r;
    int ans = 0;
    while (n--){
        int x, y; cin >> x >> y;
        if ((l - x + 24) % 24 <= (r - x + 24) % 24 && (r - x + 24) % 24 <= (y - x + 24) % 24){
            ans++;
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