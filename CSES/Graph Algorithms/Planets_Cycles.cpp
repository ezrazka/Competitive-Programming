#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; u++){
        int v; cin >> v; v--;
        adj[u].push_back(v);
    }

    vector<vector<int>> sccs;
    vector<int> disc(n, -1), low(n, -1);
    stack<int> st;
    vector<bool> in_stack(n);
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
                in_stack[st.top()] = false;
                st.pop();
            }
            scc.push_back(st.top());
            in_stack[st.top()] = false;
            st.pop();
            sccs.push_back(scc);
        }
    };

    for (int node = 0; node < n; node++){
        if (disc[node] == -1){
            tarjan(tarjan, node);
        }
    }

    vector<int> dp(n, -1);
    for (vector<int> scc : sccs){
        for (int node : scc){
            if (scc.size() > 1 || adj[node][0] == node){
                dp[node] = scc.size();
            }
        }
    }

    auto dfs = [&](auto self, int node) -> void {
        for (int child : adj[node]){
            if (dp[child] == -1) self(self, child);
            dp[node] = dp[child] + 1;
        }
    };
    for (int node = 0; node < n; node++){
        if (dp[node] == -1){
            dfs(dfs, node);
        }
    }

    for (int i = 0; i < n; i++){
        cout << dp[i] << " \n"[i == n - 1];
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