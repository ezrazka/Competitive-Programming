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

int inv(int a){
    return binpow(a, MOD - 2);
}

void solve(){
    int a, b, k; cin >> a >> b >> k;

    int n = ((a - 1) * k + 1);
    int Cna = 1;
    for (int i = n; i > n - a; i--){
        Cna = (Cna * (i % MOD)) % MOD;
        Cna = (Cna * inv((n - i + 1) % MOD)) % MOD;
    }
    int m = ((((b - 1) * Cna) % MOD * k) % MOD + 1);
    cout << n % MOD << ' ' << m % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}