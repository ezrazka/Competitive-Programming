#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n ; cin >> n;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            auto [x1, y1, r1] = v[i];
            auto [x2, y2, r2] = v[j];
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (r1 + r2) * (r1 + r2)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> dp(n);
    bool valid_coloring = true;
    vector<int> component_sizes(3);
    auto dfs = [&](auto self, int node) -> void {
        component_sizes[dp[node]]++;
        for (int child : adj[node]){
            if (dp[child] == 0){
                dp[child] = 3 - dp[node];
                self(self, child);
            } else if (dp[node] == dp[child]){
                valid_coloring = false;
            }
        }
    };

    for (int node = 0; node < n; node++){
        if (dp[node] == 0){
            dp[node] = 1;
            valid_coloring = true;
            component_sizes[1] = 0;
            component_sizes[2] = 0;
            dfs(dfs, node);
            if (valid_coloring && (component_sizes[1] != component_sizes[2])){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";

    /*
    convert problem into a bipartite coloring problem,
    alice wins if there is any valid bipartite colored component,
    where the number of nodes of each color are different
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}