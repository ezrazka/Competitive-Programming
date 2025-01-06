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

    auto rec = [&](auto self, int l, int r) -> pii {
        if (r - l + 1 < k) return {0, 0};
        int mid = (l + r) / 2;
        if ((r - l + 1) & 1){
            pii left = self(self, l, mid - 1);
            pii right = {left.fi + mid * left.se, left.se};
            return {left.fi + mid + right.fi, 2 * left.se + 1};
        }
        pii left = self(self, l, mid);
        pii right = {left.fi + mid * left.se, left.se};
        return {left.fi + right.fi, 2 * left.se};
    };

    // auto rec = [&](auto self, int l, int r) -> int {
    //     if (r - l + 1 < k) return 0;
    //     int mid = (l + r) / 2;
    //     if ((r - l + 1) & 1){
    //         return self(self, l, mid - 1) + mid + self(self, mid + 1, r);
    //     }
    //     return self(self, l, mid) + self(self, mid + 1, r);
    // };
    cout << rec(rec, 1, n).fi << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}