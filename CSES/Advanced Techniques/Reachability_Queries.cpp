#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int N = 5e4;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[v].push_back(u);
    }

    stack<int> st;
    vector<vector<int>> sccs;
    vector<int> scc;
    vector<bool> in_stack(n);
    vector<int> disc(n, -1), low(n, -1), id(n, -1);
    int timer = 0;
    auto tarjan = [&](auto self, int node) -> void {
        st.push(node);
        in_stack[node] = true;
        disc[node] = low[node] = timer++;
        for (int child : adj[node]){
            if (disc[child] == -1){
                self(self, child);
                low[node] = min(low[node], low[child]);
            } else if (in_stack[child]){
                low[node] = min(low[node], disc[child]);
            }
        }
        if (disc[node] == low[node]){
            vector<int> scc;
            while (st.top() != node){
                scc.push_back(st.top());
                id[st.top()] = sccs.size();
                in_stack[st.top()] = false;
                st.pop();
            }
            scc.push_back(st.top());
            id[st.top()] = sccs.size();
            in_stack[st.top()] = false;
            st.pop();
            reverse(scc.begin(), scc.end());
            sccs.push_back(scc);
            scc.clear();
        }
    };

    for (int node = 0; node < n; node++){
        if (disc[node] == -1){
            tarjan(tarjan, node);
        }
    }

    vector<vector<int>> condensed(sccs.size());
    vector<int> indegree(n);
    set<pii> used_edges;
    for (int node = 0; node < n; node++){
        for (int child : adj[node]){
            if (id[node] != id[child] && used_edges.find({id[node], id[child]}) == used_edges.end()){
                used_edges.insert({id[node], id[child]});
                condensed[id[node]].push_back(id[child]);
                indegree[id[child]]++;
            }
        }
    }

    queue<int> qu;
    vector<bitset<N>> reachable(sccs.size());
    for (int node = 0; node < sccs.size(); node++){
        reachable[node][node] = 1;
        if (indegree[node] == 0){
            qu.push(node);
        }
    }

    while (!qu.empty()){
        int node = qu.front(); qu.pop();
        for (int child : condensed[node]){
            reachable[child] |= reachable[node];
            if (--indegree[child] == 0){
                qu.push(child);
            }
        }
    }

    while (q--){
        int u, v; cin >> u >> v; u--, v--;
        cout << (reachable[id[u]][id[v]] ? "YES\n" : "NO\n");
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