#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int m, n; cin >> m >> n;
    vector<vector<int>> adj(2 * n);
    for (int i = 0; i < m; i++){
        char cu, cv; int u, v;
        cin >> cu >> u >> cv >> v; u--, v--;
        if (cu == '-') u += n;
        if (cv == '-') v += n;
        adj[(u + n) % (2 * n)].push_back(v);
        adj[(v + n) % (2 * n)].push_back(u);
    }

    stack<int> st;
    vector<bool> in_stack(2 * n);
    vector<int> disc(2 * n, -1), low(2 * n, -1), comp(2 * n, -1);
    int timer = 0, total_components = 0;
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
            while (st.top() != node){
                comp[st.top()] = total_components;
                in_stack[st.top()] = false;
                st.pop();
            }
            comp[st.top()] = total_components;
            in_stack[st.top()] = false;
            st.pop();
            total_components++;
        }
    };

    for (int node = 0; node < 2 * n; node++){
        if (disc[node] == -1){
            tarjan(tarjan, node);
        }
    }

    bool ok = true;
    for (int node = 0; node < n; node++){
        if (comp[node] == comp[node + n]){
            ok = false;
        }
    }

    if (!ok){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<vector<int>> compressed(total_components);
    for (int node = 0; node < 2 * n; node++){
        for (int child : adj[node]){
            if (comp[node] != comp[child]){
                compressed[comp[node]].push_back(comp[child]);
            }
        }
    }

    vector<int> indegree(total_components);
    for (int node = 0; node < total_components; node++){
        sort(compressed[node].begin(), compressed[node].end());
        compressed[node].erase(unique(compressed[node].begin(), compressed[node].end()), compressed[node].end());
        for (int child : compressed[node]){
            indegree[child]++;
        }
    }

    queue<int> q;
    for (int node = 0; node < total_components; node++){
        if (indegree[node] == 0){
            q.push(node);
        }
    }

    vector<int> topological_index(total_components);
    int index = 0;
    while (!q.empty()){
        int node = q.front(); q.pop();
        topological_index[node] = index++;
        for (int child : compressed[node]){
            if (--indegree[child] == 0){
                q.push(child);
            }
        }
    }

    for (int node = 0; node < n; node++){
        if (topological_index[comp[node]] < topological_index[comp[node + n]]){
            cout << '-' << " \n"[node == n - 1];
        } else {
            cout << '+' << " \n"[node == n - 1];
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