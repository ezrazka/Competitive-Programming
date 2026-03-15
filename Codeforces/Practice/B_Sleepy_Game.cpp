#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int node = 0; node < n; node++){
        int c; cin >> c;
        while (c--){
            int child; cin >> child; child--;
            adj[node].push_back(child);
        }
    }
    int s; cin >> s; s--;

    vector<vector<bool>> dp(n, vector<bool>(2));
    vector<vector<int>> state(n, vector<int>(2, 0)); // 0: unvisited, 1: procressing, 2: visited
    bool has_cycle = false;
    auto dfs = [&](auto self, int node, int parity) -> void {
        state[node][parity] = 1;
        for (int child : adj[node]){
            if (state[child][parity ^ 1] == 0){
                self(self, child, parity ^ 1);
            } else if (state[child][parity ^ 1] == 1){
                has_cycle = true;
            }
            if (dp[child][parity ^ 1]) dp[node][parity] = true;
        }
        if (parity == 0 && adj[node].empty()){
            dp[node][parity] = true;
        }
        state[node][parity] = 2;
    };
    dfs(dfs, s, 1);

    if (!dp[s][1] && has_cycle){
        cout << "Draw\n";
        return;
    }

    if (dp[s][1]){
        cout << "Win\n";
        int cur = s;
        int parity = 1;
        cout << cur + 1 << ' ';
        vector<vector<bool>> vis(n, vector<bool>(2));
        while (!adj[cur].empty()){
            vis[cur][parity] = true;
            for (int child : adj[cur]){
                if (vis[child][parity ^ 1]) continue;
                if (dp[child][parity ^ 1]){
                    cur = child;
                    break;
                }
            }
            parity ^= 1;
            cout << cur + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "Lose\n";
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