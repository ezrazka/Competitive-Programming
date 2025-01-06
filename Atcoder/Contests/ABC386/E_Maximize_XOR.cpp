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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;
    auto rec = [&](auto self, int xr, int idx, int cnt) -> void {
        if (cnt == k){
            ans = max(ans, xr);
            return;
        }
        if (idx == n) return;
        self(self, xr, idx + 1, cnt);
        self(self, xr ^ v[idx], idx + 1, cnt + 1);
    };
    rec(rec, 0, 0, 0);
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