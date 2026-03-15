#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int binpow(int a, int b, int m){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    int ans = n;
    for (int k = 1; k * k <= n; k++){
        if (n % k == 0){
            if (binpow(k, n, n) == 0) ans = min(ans, k);
            if (binpow(n / k, n, n) == 0) ans = min(ans, n / k);
        }
    }
    cout << ans << '\n';
    /*
    k^n % n == 0

    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}