#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<int> v(k);
    for (int i = 0; i < k; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    auto dnc = [&](auto self, int l, int r) -> int {
        int cnt = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
        if (cnt > 0){
            int res = b * (r - l + 1) * cnt;
            if (l != r){
                int mid = (l + r) / 2;
                res = min(res, self(self, l, mid) + self(self, mid + 1, r));
            }
            return res;
        }
        return a;
    };

    cout << dnc(dnc, 1, (1 << n)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}