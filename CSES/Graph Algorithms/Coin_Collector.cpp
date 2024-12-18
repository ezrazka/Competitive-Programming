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
    vector<int> coins(n);
    for (int node = 0; node < n; node++){
        cin >> coins[node];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> in_stack(n);
    vector<int> disc(n, -1), low(n, -1), comp(n, -1);
    int timer = 0, total_components = 0;
    vector<int> scc_coins;
    auto dfs = [&](auto self, int node) -> void {
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
            scc_coins.push_back(0);
            while (st.top() != node){
                comp[st.top()] = total_components;
                scc_coins[total_components] += coins[st.top()];
                in_stack[st.top()] = false;
                st.pop();
            }
            comp[st.top()] = total_components;
            scc_coins[total_components] += coins[st.top()];
            in_stack[st.top()] = false;
            st.pop();
            total_components++;
        }
    };

    for (int node = 0; node < n; node++){
        if (disc[node] == -1){
            dfs(dfs, node);
        }
    }

    vector<vector<int>> compressed(total_components);
    for (int node = 0; node < n; node++){
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
    vector<int> dp(total_components);
    for (int node = 0; node < total_components; node++){
        if (indegree[node] == 0){
            q.push(node);
        }
    }
    while (!q.empty()){
        int node = q.front(); q.pop();
        dp[node] = max(dp[node], scc_coins[node]);
        for (int child : compressed[node]){
            dp[child] = max(dp[child], dp[node] + scc_coins[child]);
            if (--indegree[child] == 0){
                q.push(child);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}