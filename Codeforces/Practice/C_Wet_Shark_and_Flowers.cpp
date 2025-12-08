#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, p; cin >> n >> p;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }

    ld ans = 0;
    for (int i = 0; i < n; i++){
        int l1 = l[i], l2 = l[(i + 1) % n];
        int r1 = r[i], r2 = r[(i + 1) % n];
        ld p1 = (ld) (r2 / p - (l2 - 1) / p) / (r2 - l2 + 1);
        ld p2 = (ld) (r1 / p - (l1 - 1) / p) / (r1 - l1 + 1);
        ans += p1 + p2 - p1 * p2;
    }
    ans *= 2000;
    cout << fixed << setprecision(10) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}