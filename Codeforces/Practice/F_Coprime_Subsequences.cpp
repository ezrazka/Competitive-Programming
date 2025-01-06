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
    vector<int> freq(1e5 + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> dp(1e5 + 1);
    for (int i = 1e5; i >= 1; i--){
        int cnt = 0;
        for (int j = i; j <= 1e5; j += i){
            cnt += freq[j];
            dp[i] = (dp[i] - dp[j]) % MOD;
        }
        dp[i] = (dp[i] + (binpow(2, cnt) - 1) + MOD) % MOD;
    }
    cout << dp[1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}