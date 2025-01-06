#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> v(q);
    for (int i = 0; i < q; i++){
        cin >> v[i];
    }

    int l = m, r = m;
    int pre = 0, suf = 0;
    for (int i = 0; i < q; i++){
        if (pre > 0 && v[i] > pre) pre++;
        if (suf > 0 && v[i] < n - suf + 1) suf++;
        if (l <= v[i] && v[i] <= r){
            pre = max(pre, 1ll);
            suf = max(suf, 1ll);
            if (l == r){
                l = -1;
                r = -1;
            }
        }
        if (l != -1 && v[i] < l) l--;
        if (r != -1 && v[i] > r) r++;

        int res;
        if (l != -1 && r != -1){
            res = pre + (r - l + 1) + suf - max(0ll, min(pre, r) - l + 1) - max(0ll, r - max(n - suf + 1, l) + 1);
        } else {
            res = min(n, pre + suf);
        }

        cout << res << " \n"[i == q - 1];
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