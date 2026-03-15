#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    auto calc = [&](int x){
        int res = x;
        if ((x - 1) / n > 0) res += x - n;
        if ((x - 1) / n < n - 1) res += x + n;
        if ((x - 1) % n > 0) res += x - 1;
        if ((x - 1) % n < n - 1) res += x + 1;
        return res;
    };

    int ans = 0;
    for (int i = 1; i <= n * n; i++){
        ans = max(ans, calc(i));
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