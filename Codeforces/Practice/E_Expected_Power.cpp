#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;
const int INV10000 = 285700002;

int mult(int a, int b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> bit_ev(10);
    for (int bit = 0; bit < 10; bit++){
        vector<int> dp(2); dp[0] = 1;
        for (int i = 0; i < n; i++){
            if (a[i] & (1 << bit)){
                vector<int> next(2);
                next[0] += mult(dp[0], mult(10000 - p[i], INV10000));
                next[0] += mult(dp[1], mult(p[i], INV10000));
                next[1] += mult(dp[1], mult(10000 - p[i], INV10000));
                next[1] += mult(dp[0], mult(p[i], INV10000));
                dp = next;
            }
        }
        bit_ev[bit] = mult(dp[1], (1 << bit));
    }

    int ans = 0;
    for (int i = 0; i < 10; i++){
        ans += bit_ev[i];
    }

    int ans_squared = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            
        }
    }

    cout << ans_squared << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}