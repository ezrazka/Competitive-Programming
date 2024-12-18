#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n);
    vector<vector<int>> adj2(n);
    set<pii> edges;
    auto dfs = [&](auto self, int node) -> void {
        vis[node] = true;
        for (int child : adj[node]){
            if (edges.find({child, node}) != edges.end()) continue;
            edges.insert({node, child});
            if (!vis[child]){
                adj2[node].push_back(child);
                self(self, child);
            } else {
                adj2[node].push_back(child);
            }
        }
    };

    for (int node = 0; node < n; node++){
        if (!vis[node]){
            dfs(dfs, node);
        }
    }

    bool ok = true;
    stack<int> st;
    vector<bool> in_stack(n);
    vector<int> disc(n, -1), low(n, -1);
    int timer = 0;
    auto tarjan = [&](auto self, int node) -> void {
        st.push(node);
        in_stack[node] = true;
        disc[node] = low[node] = timer++;
        for (int child : adj2[node]){
            if (disc[child] == -1){
                self(self, child);
                low[node] = min(low[node], low[child]);
            } else if (in_stack[child]){
                low[node] = min(low[node], disc[child]);
            }
        }
        if (disc[node] == low[node]){
            while (st.top() != node){
                in_stack[st.top()] = false;
                st.pop();
            }
            in_stack[st.top()] = false;
            st.pop();
            if (node != 0){
                ok = false;
            }
        }
    };

    for (int node = 0; node < n; node++){
        if (disc[node] == -1){
            tarjan(tarjan, node);
        }
    }

    if (!ok){
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int node = 0; node < n; node++){
        for (int child : adj2[node]){
            cout << node + 1 << ' ' << child + 1 << '\n';
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