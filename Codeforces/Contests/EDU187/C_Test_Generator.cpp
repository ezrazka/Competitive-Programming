#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int s, m; cin >> s >> m;

    if ((s & -s) < (m & -m)){
        cout << -1 << '\n';
        return;
    }

    int l = 1, r = 1e18, ans;
    while (l <= r){
        int mid = (l + r) / 2;

        vector<int> bits(60);
        for (int bit = 0; bit < 60; bit++){
            if (m & (1ll << bit)) bits[bit] = mid;
        }

        bool possible = true;
        for (int bit = 0; bit < 60; bit++){
            if (!(s & (1ll << bit))) continue;
            int need = (1ll << bit);
            for (int bit2 = bit; bit2 >= 0; bit2--){
                int take = min(bits[bit2], need >> bit2);
                need -= (take << bit2);
                bits[bit2] -= take;
                if (need == 0) break;
            }
            if (need > 0){
                possible = false;
                break;
            }
        }

        if (!possible){
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans << '\n';
    // 1011
    // 101

    // 1011
    // 11
    /*
    array when sum is s, and every value is included in m
    we can choose any bit in m, 0 to n times
    but it must minimize n

    -1 if the smallest bit in s is 

    if there are any bits in s not in m, we keep adding the
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}