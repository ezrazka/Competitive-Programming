#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> fact(30 + 1);

int P(int n, int r){
    return fact[n] / fact[n - r];
}

int C(int n, int r){
    return P(n, r) / fact[r];
}

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 30; i++){
        fact[i] = fact[i - 1] * i;
    }
}

void solve(){
    int n, k; cin >> n >> k;

    int ans = (__lg(n) + 1 > k);
    for (int bits = 0; bits <= __lg(n); bits++){
        for (int i = max(0ll, k - bits + 1); i <= bits - 1; i++){
            ans += C(bits - 1, i);
        }
    }

    cout << ans << '\n';

    // 0 : 1 operation
    // 1 : 2 operations
    // fix the number of bits,
    // count number of ways to have bits + ones > k, where the biggest bit is 1
    /*
    for bits in range(__lg(n)):
        for i in range(k - bits + 1, bits - 1):
            ans += C(bits - 1, i)
    */
        // for i in range(bits - 1) -> sum of C(bits - 1, ones - 1)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}