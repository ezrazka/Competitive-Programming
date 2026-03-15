#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;

    if (a > b * c){
        cout << "-1\n";
        return;
    }

    auto calc = [&](int x) -> int {
        if (x == 0) return 0;
        int heal;
        if (c <= d){
            heal = (x - 1) * c;
        } else {
            int n = c / d;
            if (x - 1 <= n) heal = d * (x - 1) * x / 2;
            else heal = d * n * (n + 1) / 2 + d * ((x - 1) - n) * c;
        }
        return x * a - b * heal;
    };

    int l = 0, r = (c + d - 1) / d + 1, ans;
    while (l <= r){
        int mid = (l + r) / 2;

        if (calc(mid) < calc(mid + 1)){
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = calc(mid);
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