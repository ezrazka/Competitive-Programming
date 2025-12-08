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

    int ans = 1;
    int winners = n, losers = 0;
    while (winners != 1 || losers != 1){
        ans += winners / 2 + losers / 2;
        losers = (losers + 1) / 2 + winners / 2;
        winners = (winners + 1) / 2;
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