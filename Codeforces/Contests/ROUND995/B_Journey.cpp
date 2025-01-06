#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, c, n; cin >> n >> a >> b >> c;

    int ans = n / (a + b + c) * 3;
    n -= ans / 3 * (a + b + c);
    if (n == 0){
        cout << ans << '\n';
    } else if (a >= n){
        cout << ans + 1 << '\n';
    }  else if (a + b >= n){
        cout << ans + 2 << '\n';
    } else {
        cout << ans + 3 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}