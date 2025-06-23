#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

int binpow(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> vans(n);
    int argmx_a = -1, argmx_b = -1;
    for (int i = 0; i < n; i++){
        if (i == 0 || a[i] > a[argmx_a]) argmx_a = i;
        if (i == 0 || b[i] > b[argmx_b]) argmx_b = i;
        if (a[argmx_a] > b[argmx_b] || (a[argmx_a] == b[argmx_b] && a[i - argmx_b] < b[i - argmx_a])){
            vans[i] = (binpow(2, a[argmx_a]) + binpow(2, b[i - argmx_a])) % MOD;
        } else {
            vans[i] = (binpow(2, a[i - argmx_b]) + binpow(2, b[argmx_b])) % MOD;
        }
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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