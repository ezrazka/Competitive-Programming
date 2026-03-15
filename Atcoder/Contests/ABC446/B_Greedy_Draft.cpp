#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<bool> vis(m + 1);
    while (n--){
        int k; cin >> k;
        bool found = false;
        while (k--){
            int x; cin >> x;
            if (!found && !vis[x]){
                cout << x << '\n';
                vis[x] = true;
                found = true;
            }
        }
        if (!found) cout << 0 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}