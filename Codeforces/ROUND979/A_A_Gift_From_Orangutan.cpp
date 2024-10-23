#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        rotate(v.begin(), v.end() - 1, v.end());

        vector<int> a = v, b = v;
        for (int i = 1; i < n; i++){
            a[i] = min(a[i - 1], v[i]);
            b[i] = max(b[i - 1], v[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += b[i] - a[i];
        }
        cout << ans << '\n';
    }
}