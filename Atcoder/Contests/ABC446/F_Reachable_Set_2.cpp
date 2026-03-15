#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < m; _++){
        int u, v; cin >> u >> v; u--, v--;
        if (u == v) continue;
        adj[u].push_back(v);
    }
    {
        vector<vector<int>> new_adj(n);
        vector<int> state(n);
        auto dfs = [&](auto self, int node) -> void {
            state[node] = 1;
            for (int child : adj[node]){
                if (state[child] == 1) continue;
                if (state[child] == 0) self(self, child);
                new_adj[node].push_back(child);
            }
            state[node] = 2;
        };
        dfs(dfs, 0);
        adj = new_adj;
    }

    vector<bool> possible(n);
    {
        vector<int> indegree(n);
        for (int node = 0; node < n; node++){
            for (int child : adj[node]){
                indegree[child]++;
            }
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(0);
        
        vector<int> topo;
        while (!pq.empty()){
            int node = pq.top(); pq.pop();
            topo.push_back(node);
            for (int child : adj[node]){
                if (--indegree[child] == 0){
                    pq.push(child);
                }
            }
        }

        set<int> mex;
        for (int i = 0; i <= n; i++) mex.insert(i);
        for (int i = 0; i < n; i++){
            if (i >= topo.size()){
                possible[i] = false;
                continue;
            }
            mex.erase(topo[i]);
            if (*mex.begin() == i + 1){
                possible[i] = true;
            }
        }
    }

    vector<vector<int>> adj_t(n);
    for (int node = 0; node < n; node++){
        for (int child : adj[node]){
            adj_t[child].push_back(node);
        }
    }
    
    vector<int> vans(n);
    vector<int> cnt(n);
    for (int node = 0; node < n; node++){
        if (node - 1 >= 0) vans[node] = vans[node - 1];
        for (int child : adj[node]){
            if (node < child){
                cnt[child]++;
                if (cnt[child] == 1) vans[node]++;
            }
        }
        for (int child : adj_t[node]){
            if (child < node){
                cnt[node]--;
                if (cnt[node] == 0) vans[node]--;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << (possible[i] ? vans[i] : -1) << '\n';
    }

    /*
    1. is it connected?
    2. how many must be removed?
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