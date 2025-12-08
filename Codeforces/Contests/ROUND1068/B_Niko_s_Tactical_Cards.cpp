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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> mn(n + 1), mx(n + 1);
    mn[0] = 0, mx[0] = 0;
    for (int i = 1; i <= n; i++){
        mn[i] = min(b[i - 1] - mx[i - 1], mn[i - 1] - a[i - 1]);
        mx[i] = max(mx[i - 1] - a[i - 1], b[i - 1] - mn[i - 1]);
    }
    cout << mx[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}