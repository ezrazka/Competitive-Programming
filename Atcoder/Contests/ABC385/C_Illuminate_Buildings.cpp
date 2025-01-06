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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 1;
    for (int jump = 1; jump <= n; jump++){
        for (int start = 0; start < jump; start++){
            int max_len = 1, len = 0, prev = -1;
            for (int i = start; i < n; i += jump){
                if (v[i] == prev){
                    len++;
                } else {
                    max_len = max(max_len, len);
                    len = 1;
                }
                prev = v[i];
            }
            max_len = max(max_len, len);
            ans = max(ans, max_len);
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