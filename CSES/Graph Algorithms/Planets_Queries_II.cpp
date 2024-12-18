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
    vector<int> indegree(n);
    for (int i = 0; i < n; i++){
        cin >> adj[i], adj[i]--;
        indegree[adj[i]]++;
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

    vector<bool> is_cycle(n);
    for (int node = 0; node < n; node++){
        if (sccs[scc_id[node]].size() > 1 || adj[node] == node){
            is_cycle[node] = true;
        }
    }

    vector<vector<int>> lines;
    vector<int> line_id(n, -1);
    vector<int> line_idx(n, -1);
    vector<int> line;
    auto dfs = [&](auto self, int node) -> void {
        if (is_cycle[node]){
            line_id[node] = lines.size();
            line_idx[node] = line.size();
            line.push_back(node);
            return;
        }
        line_id[node] = lines.size();
        line_idx[node] = line.size();
        line.push_back(node);
        int child = adj[node];
        self(self, child);
    };
    for (int node = 0; node < n; node++){
        if (indegree[node] == 0){
            dfs(dfs, node);
            lines.push_back(line);
            line.clear();
        }
    }

    while (q--){
        int a, b; cin >> a >> b; a--, b--;
        if (line_id[a] != 1 && line_id[b] != -1 && line_id[a] == line_id[b] && line_idx[a] < line_idx[b]){
            cout << line_idx[b] - line_idx[a] << '\n';
        } else if (line_id[a] != -1 && scc_id[lines[line_id[a]].back()] == scc_id[b]){
            int origin_to_cycle = (lines[line_id[a]].size() - 1) - line_idx[a];
            int cycle_to_target = (scc_idx[b] - scc_idx[lines[line_id[a]].back()] + sccs[scc_id[b]].size()) % sccs[scc_id[b]].size();
            cout << origin_to_cycle + cycle_to_target << '\n';
        } else if (scc_id[a] == scc_id[b]){
            cout << (scc_idx[b] - scc_idx[a] + sccs[scc_id[a]].size()) % sccs[scc_id[a]].size() << '\n';
        } else {
            cout << -1 << '\n';
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