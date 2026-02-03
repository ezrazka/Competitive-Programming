#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    int l = 1, r = n * n, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;

        int cnt = 0;
        for (int i = 1; i <= n; i++){
            cnt += min(n, mid / i);
        }

        if (cnt < (n * n + 1) / 2){
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
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