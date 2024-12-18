#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int q; cin >> q;

    while (q--){
        int n, k; cin >> n >> k;

        auto rec = [&](auto self, int n, int k, bool odd) -> int {
            int to_remove = (n + odd) / 2;
            if (k <= to_remove) return 2 * k - odd;
            int val = self(self, n - to_remove, k - to_remove, odd ^ (n & 1));
            if (odd) return 2 * val;
            return 2 * val - 1;
        };
        cout << rec(rec, n, k, false) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}