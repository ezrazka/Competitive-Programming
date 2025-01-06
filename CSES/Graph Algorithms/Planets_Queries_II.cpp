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
    vector<int> adj(n);
    for (int i = 0; i < n; i++){
        cin >> adj[i]; adj[i]--;
    }
 
    vector<vector<pii>> queries(n);
    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b; a--, b--;
        queries[a].push_back({b, i});
    }
 
    vector<int> scc_id(n, -1);
    vector<vector<int>> sccs;
    vector<int> scc_idx(n, -1);
    vector<int> disc(n, -1), low(n, -1);
    stack<int> st;
    vector<bool> in_stack(n);
    int timer = 0;
    auto tarjan = [&](auto self, int node) -> void {
        st.push(node);
        in_stack[node] = true;
        disc[node] = low[node] = timer++;
        int child = adj[node];
        if (disc[child] == -1){
            self(self, child);
            low[node] = min(low[node], low[child]);
        } else if (in_stack[child]){
            low[node] = min(low[node], disc[child]);
        }
        if (disc[node] == low[node]){
            vector<int> scc;
            while (st.top() != node){
                scc_id[st.top()] = sccs.size();
                scc.push_back(st.top());
                in_stack[st.top()] = false;
                st.pop();
            }
            scc_id[st.top()] = sccs.size();
            scc.push_back(st.top());
            in_stack[st.top()] = false;
            st.pop();
            reverse(scc.begin(), scc.end());
            for (int i = 0; i < scc.size(); i++){
                scc_idx[scc[i]] = i;
            }
            sccs.push_back(scc);
        }
    };
    for (int node = 0; node < n; node++){
        if (disc[node] == -1){
            tarjan(tarjan, node);
        }
    }
 
    vector<bool> is_cycle(n), is_tree(n);
    for (int node = 0; node < n; node++){
        if (sccs[scc_id[node]].size() > 1 || adj[node] == node){
            is_cycle[node] = true;
        } else {
            is_tree[node] = true;
        }
    }
    
    vector<vector<int>> transposed(n);
    for (int node = 0; node < n; node++){
        transposed[adj[node]].push_back(node);
    }

    vector<vector<int>> tree(n);
    vector<int> tree_id(n, -1);
    vector<int> tree_roots;
    bool empty = true;
    auto dfs = [&](auto self, int node) -> void {
        for (int child : transposed[node]){
            if (is_tree[child]){
                empty = false;
                tree[node].push_back(child);
                tree_id[child] = tree_roots.size();
                self(self, child);
            }
        }
    };
 
    for (int node = 0; node < n; node++){
        if (is_cycle[node]){
            dfs(dfs, node);
            if (!empty){
                tree_roots.push_back(node);
                empty = true;
            }
        }
    }
 
    vector<int> vans(q);
    vector<vector<int>> up(n, vector<int>(18, -1));
    vector<int> depth(n);
    for (int i = 0; i < tree_roots.size(); i++){
        vector<int> nodes;
        auto dfs2 = [&](auto self, int node) -> void {
            for (int child : tree[node]){
                depth[child] = depth[node] + 1;
                up[child][0] = node;
                nodes.push_back(child);
                self(self, child);
            }
        };
        dfs2(dfs2, tree_roots[i]);
 
        for (int bit = 1; bit < 18; bit++){
            for (int node : nodes){
                if (up[node][bit - 1] != -1){
                    up[node][bit] = up[up[node][bit - 1]][bit - 1];
                }
            }
        }
 
        auto lca = [&](int a, int b){
            if (depth[a] > depth[b]) swap(a, b);
            int diff = max(0ll, depth[b] - depth[a]);
 
            for (int bit = 0; bit < 18; bit++){
                if (diff & (1 << bit)){
                    b = up[b][bit];
                }
            }
 
            if (a == b){
                return a;
            }
 
            for (int bit = 17; bit >= 0; bit--){
                if (up[a][bit] != up[b][bit]){
                    a = up[a][bit];
                    b = up[b][bit];
                }
            }
 
            return up[a][0];
        };
 
        for (int node : nodes){
            for (auto [target, index] : queries[node]){
                if (is_cycle[target] && scc_id[target] == scc_id[tree_roots[i]]){
                    int dist_to_cycle = depth[node];
                    int dist_to_target = (scc_idx[target] - scc_idx[tree_roots[i]] + sccs[scc_id[target]].size()) % sccs[scc_id[target]].size();
                    vans[index] = dist_to_cycle + dist_to_target;
                } else if (is_tree[target] && tree_id[node] == tree_id[target] && lca(node, target) == target){
                    vans[index] = depth[node] - depth[target];
                } else {
                    vans[index] = -1;
                }
            }
        }
    }
 
    for (int node = 0; node < n; node++){
        if (is_cycle[node]){
            for (auto [target, index] : queries[node]){
                if (is_cycle[target] && scc_id[node] == scc_id[target]){
                    int dist_to_target = (scc_idx[target] - scc_idx[node] + sccs[scc_id[node]].size()) % sccs[scc_id[node]].size();
                    vans[index] = dist_to_target;
                } else {
                    vans[index] = -1;
                }
            }
        }
    }
 
    for (int i = 0; i < q; i++){
        cout << vans[i] << '\n';
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