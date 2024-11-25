#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;

    if (n % 2 == 0){
        cout << ((binpow(2, n * n) - 2 * binpow(2, n * n / 2) - binpow(2, n * n / 4)) % MOD + MOD) % MOD << '\n';
    }
    /*
    00 11 10 11 11 10
    00 11 00 00 01 01
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}