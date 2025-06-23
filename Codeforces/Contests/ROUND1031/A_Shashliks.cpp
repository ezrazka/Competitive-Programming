#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int k; cin >> k;
    pair<int, int> a, b; cin >> a.fi >> b.fi >> a.se >> b.se;
    if (a.se > b.se) swap(a, b);
    int ans = 0;
    if (k >= a.fi){
        ans += (k - a.fi + a.se) / a.se;
        k -= (k - a.fi + a.se) / a.se * a.se;
    }
    if (k >= b.fi){
        ans += (k - b.fi + b.se) / b.se;
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