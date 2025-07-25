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
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += max(0ll, a[i] - c[i]);
        if (b[i] > d[i]){
            ans += min(a[i], c[i]);
            ans += b[i] - d[i];
        }
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