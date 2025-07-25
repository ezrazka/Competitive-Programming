#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, l, r, k; cin >> n >> l >> r >> k;
    if (n % 2 == 1){
        cout << l << '\n';
        return;
    } else if (n < 4){
        cout << -1 << '\n';
        return;
    }

    int x = (1ll << 64 - __builtin_clzll(l));
    if (x > r){
        cout << -1 << '\n';
        return;
    }

    if (k <= n - 2){
        cout << l << '\n';
    } else {
        cout << x << '\n';
    }

    // if n is odd, ans is l
    // n % 4 == 2, ans is -1
    // has to be disjoint
    // if l = 1, r = 2, works only if div by 4
    // is it possible that its optimal to choose >2 values?
    // 7 14 28
    // l and the next power of 2 after l
} // 7 bits

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}