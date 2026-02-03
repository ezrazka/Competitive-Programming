#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] & 1;
    }

    vector<vector<int>> adj(n), adj1(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (a[u] == 1 && a[v] == 1){
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
    }

    vector<bool> deleted(n);
    vector<int> vans;
    for (int node = 0; node < n; node++){
        int one_neighbors = 0;
        for (int child : adj[node]){
            if (a[child] == 1) one_neighbors++;
        }
        if (a[node] == 0 && one_neighbors & 1){
            deleted[node] = true;
            vans.push_back(node);
        }
    }

    vector<int> sz(n);
    {
        vector<bool> visited(n);
        auto dfs_sz = [&](auto self, int node, int parent) -> void {
            visited[node] = true;
            sz[node] = 1;
            for (int child : adj1[node]){
                if (child != parent){
                    self(self, child, node);
                    sz[node] += sz[child];
                }
            }
        };
        for (int node = 0; node < n; node++){
            if (a[node] == 1 && !visited[node]){
                dfs_sz(dfs_sz, node, -1);
            }
        }
    }

    vector<bool> need_parent(n);
    {
        vector<bool> visited(n);
        bool ok = true;
        auto dfs = [&](auto self, int node, int parent) -> void {
            visited[node] = true;
            need_parent[node] = (sz[node] % 2 == 0);
            
            int solo_children = 0;
            for (int child : adj1[node]){
                if (child != parent){
                    self(self, child, node);
                    if (!need_parent[child]) solo_children++;
                }
            }

            bool must_have_parent = solo_children & 1;
            if (
                must_have_parent && (!need_parent[node] || parent == -1) ||
                (!must_have_parent || parent == -1) && need_parent[node]
            ){
                ok = false;
            }
        };
        for (int node = 0; node < n; node++){
            if (a[node] == 1 && !visited[node]){
                dfs(dfs, node, -1);
            }
        }
    
        if (!ok){
            cout << "NO\n";
            return;
        }
    }

    vector<int> ones_order;
    {
        vector<bool> visited(n);
        auto dfs_ones_order = [&](auto self, int node, int parent) -> void {
            visited[node] = true;

            for (int child : adj1[node]){
                if (child != parent){
                    if (need_parent[child]){
                        self(self, child, node);
                    }
                }
            }
            ones_order.push_back(node);
            for (int child : adj1[node]){
                if (child != parent){
                    if (!need_parent[child]){
                        self(self, child, node);
                    }
                }
            }
        };
        for (int node = 0; node < n; node++){
            if (a[node] == 1 && !visited[node]){
                dfs_ones_order(dfs_ones_order, node, -1);
            }
        }
    }

    for (int node : ones_order){
        deleted[node] = true;
        vans.push_back(node);
        for (int child : adj[node]){
            if (a[child] == 0 && !deleted[child]){
                deleted[child] = true;
                vans.push_back(child);
            }
        }
    }

    if (vans.size() < n){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        cout << vans[i] + 1 << " \n"[i == n - 1];
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