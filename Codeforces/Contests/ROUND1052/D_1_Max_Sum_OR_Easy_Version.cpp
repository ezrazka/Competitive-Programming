#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int l, r; cin >> l >> r;
    vector<int> vans(r - l + 1);
    iota(vans.begin(), vans.end(), l);
    {
        int cur_l = l;
        do {
            int len = (1 << __lg(r - cur_l + 1));
            for (int i = cur_l; i < cur_l + len; i++){
                if (i + len > r) break;
                swap(vans[i - l], vans[i + len - l]);
            }
            cur_l += len;
        } while (cur_l < r);
    }
    {
        int cur_l = l;
        do {
            int len = (1 << __lg(r - cur_l + 1));
            reverse(vans.begin() + cur_l - l, vans.begin() + cur_l + len - l);
            cur_l += len;
        } while (cur_l < r);
    }
    {
        int ans = 0;
        for (int i = l; i <= r; i++){
            ans += i | vans[i - l];
        }
        cout << ans << '\n';
        for (int i = l; i <= r; i++){
            cout << vans[i - l] << " \n"[i == r];
        }
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