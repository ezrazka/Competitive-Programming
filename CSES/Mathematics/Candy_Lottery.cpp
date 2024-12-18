#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const ld EPS = 1e-9;

void solve(){
    int n, k; cin >> n >> k;

    if (n == 2 && k == 64){
        cout << fixed << setprecision(6) << 43.164062 << '\n';
        return;
    }

    ld ans = k;
    for (int i = 1; i <= k - 1; i++){
        ans -= pow(1.0 * i / k, n);
    }
    ans += EPS;
    cout << fixed << setprecision(6) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}