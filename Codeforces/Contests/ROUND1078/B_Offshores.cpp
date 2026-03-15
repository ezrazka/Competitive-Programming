#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += (a[i] / x) * y;
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, a[i] + sum - (a[i] / x) * y);
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