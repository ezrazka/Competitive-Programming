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
    int down[n][30];
    for (int node = 0; node < n; node++){
        int child; cin >> child; child--;
        down[node][0] = child;
    }

    for (int bit = 1; bit < 30; bit++){
        for (int i = 0; i < n; i++){
            down[i][bit] = down[down[i][bit - 1]][bit - 1];
        }
    }

    while (q--){
        int start, k; cin >> start >> k; start--;

        int node = start;
        for (int bit = 0; bit < 30; bit++){
            if (k & (1 << bit)){
                node = down[node][bit];
            }
        }
        cout << node + 1 << '\n';
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