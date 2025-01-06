#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(1);
    for (int i = 0; i < q; i++){
        int qq; cin >> qq;
        if (qq == 1){
            int k, a, x; cin >> k >> a >> x; k--, a--;
        } else if (qq == 2){
            int k, a, b; cin >> k >> a >> b; k--, a--, b--;
        } else {
            int k; cin >> k; k--;
        }
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