#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;
const int MX = 1e6;

vector<int> spf(MX + 1);

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1, spf[1] = -1;
    for (int i = 2; i * i <= MX; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= MX; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<bool> found(MX + 1);
    for (int i = 1; i <= n; i++){
        int temp = a[i];
        for (int temp = a[i]; temp > 1; temp /= spf[temp]){
            found[spf[temp]] = true;
        }
    }

    int ans = 1;
    for (int prime = 2; prime <= MX; prime++){
        if (found[prime]){
            vector<int> dp(20), ndp(20);
            {
                int cnt = 0;
                for (int temp = a[1]; temp > 1; temp /= prime){
                    cnt++;
                }
                for (int i = 0; i <= cnt; i++){
                    dp[i] = 1;
                }
            }
            for (int i = 2; i <= n + 1; i++){
                int cnt = 0;
                for (int temp = a[i - 1]; temp > 1; temp /= prime){
                    cnt++;
                }
                for (int j = 0; j <= cnt; j++){
                    ndp[cnt] += dp[j];
                    ndp[cnt] %= MOD;
                    if (j != cnt){
                        ndp[j] += dp[cnt];
                        ndp[j] %= MOD;
                    }
                }
                fill(dp.begin(), dp.end(), 0); // bottleneck
                swap(dp, ndp);
            }

            int cur = 0;
            for (int i = 0; i < 20; i++){
                ans += dp[i];
                ans %= MOD;
            }
            cout << prime << ' ' << cur << '\n';
            ans *= cur;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
}

signed main(){
    init();
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}