#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parity(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                parity[child] = parity[node] ^ 1;
                self(self, child, node);
            }
        }
    };
    parity[0] = 0;
    dfs(dfs, 0 , -1);

    vector<int> indegree(n);
    for (int node = 0; node < n; node++){
        indegree[node] = adj[node].size();
    }

    vector<queue<int>> leaves(2);
    for (int node = 0; node < n; node++){
        if (indegree[node] == 1 && node != n - 1){
            leaves[parity[node]].push(node);
        }
    }

    vector<vector<int>> vans;
    int cur_parity = 0;
    bool must_move = false;
    while (!leaves[0].empty() || !leaves[1].empty()){
        if (must_move || leaves[!cur_parity].empty()){
            vans.push_back({1});
            cur_parity ^= 1;
            must_move = false;
        } else {
            int leaf = leaves[!cur_parity].front();
            leaves[!cur_parity].pop();
            vans.push_back({2, leaf + 1});
            for (int child : adj[leaf]){
                if (--indegree[child] == 1 && child != n - 1){
                    leaves[parity[child]].push(child);
                }
            }
            must_move = true;
        }
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        for (int val : vans[i]){
            cout << val << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}