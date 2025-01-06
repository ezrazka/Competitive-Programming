#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

// vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 34, 37, 41, 43};
// int product = (int) 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 34 * 37 * 41 * 43;

void solve(){
    int l, r, g; cin >> l >> r >> g;
    l = (l + g - 1) / g;
    r = r / g;
    if (l == r){
        if (l == 1){
            cout << g << ' ' << g << '\n';

        } else {
            cout << "-1 -1" << '\n';
        }
    } else {
        array<int, 3> ans = {(int) 1e9, -1, -1};
        for (int k = l; k <= r; k++){
            for (int i = r; -ans[0] < (r - k + 1); i--){
                if (__gcd(k, i) == 1){
                    ans = min(ans, {-(i - k + 1), k * g, i * g});
                    break;
                }
            }
            if (r - k + 1 < -ans[0]){
                break;
            }
        }
        cout << ans[1] << ' ' << ans[2] << '\n';
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