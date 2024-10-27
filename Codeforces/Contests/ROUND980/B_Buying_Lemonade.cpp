#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int l = 1, r = 1e9, ans = -1;
        while (l <= r){
            int mid = (l + r) / 2;

            int val = 0;
            int extra = 0;
            for (int i = 0; i < n; i++){
                val += min(mid, v[i]);
                if (v[i] < mid) extra++;
            }

            if (val < k){
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = k + extra;
            }
        }
        cout << ans << '\n';
    }
}