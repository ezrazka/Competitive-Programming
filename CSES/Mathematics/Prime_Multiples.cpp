#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> primes(k);
    for (int i = 0; i < k; i++){
        cin >> primes[i];
    }

    int ans = 0;
    auto rec = [&](auto self, int idx, int cnt, int product) -> void {
        if (idx == k){
            if (cnt == 0) return;
            if (cnt & 1){
                ans += n / product;
            } else {
                ans -= n / product;
            }
            return;
        }

        self(self, idx + 1, cnt, product);
        if (product <= n / primes[idx]){
            self(self, idx + 1, cnt + 1, product * primes[idx]);
        }
    };
    rec(rec, 0, 0, 1);

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}