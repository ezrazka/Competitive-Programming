#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(int u, int v){
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int x; cin >> x;
    return x;
}

void answer(int u){
    cout << "! " << u + 1 << endl;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        par[node] = parent;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
            }
        }
    };
    dfs(dfs, 0, -1);

    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int child : adj[u]){
            if (child != par[u]){
                q.push(child);
            }
        }
        if (q.empty()){
            answer(u);
            return;
        }
        int v = q.front(); q.pop();
        for (int child : adj[v]){
            if (child != par[v]){
                q.push(child);
            }
        }

        int x = query(u, v);
        if (x == 1){
            int x = query(u, u);
            answer(x == 1 ? u : v);
            return;
        }
    }

    /*
        WLOG assume root is at 0,
        convert undirected tree to DAG,
        always choose 2 0 indegree nodes
        (it can be shown that the answer is one of the 2 nums if query returns "1")
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}