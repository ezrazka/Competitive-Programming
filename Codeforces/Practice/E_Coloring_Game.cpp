#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n);
    vector<vector<int>> teams(3);
    bool alice = false;
    auto dfs = [&](auto self, int node) -> void {
        for (int child : adj[node]){
            if (dp[child] == 0){
                dp[child] = 3 - dp[node];
                teams[dp[child]].push_back(child);
                self(self, child);
            } else if (dp[node] == dp[child]){
                alice = true;
            }
        }
    };
    dp[0] = 1;
    teams[dp[0]].push_back(0);
    dfs(dfs, 0);

    if (alice){
        cout << "Alice" << endl;
        for (int i = 0; i < n; i++){
            cout << 1 << ' ' << 2 << endl;
            int x, y; cin >> x >> y;
        }
    } else {
        cout << "Bob" << endl;
        int ones_ptr = 0, twos_ptr = 0;
        for (int i = 0; i < n; i++){
            int x, y; cin >> x >> y;
            if (ones_ptr < teams[1].size() && twos_ptr < teams[2].size()){
                if (x == 1 || y == 1){
                    cout << teams[1][ones_ptr++] + 1 << ' ' << 1 << endl;
                } else if (x == 2 || y == 2){
                    cout << teams[2][twos_ptr++] + 1 << ' ' << 2 << endl;
                }
            } else if (ones_ptr == teams[1].size()){
                if (x == 1) swap(x, y);
                cout << teams[2][twos_ptr++] + 1 << ' ' << x << endl;
            } else {
                if (x == 2) swap(x, y);
                cout << teams[1][ones_ptr++] + 1 << ' ' << x << endl;
            }
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