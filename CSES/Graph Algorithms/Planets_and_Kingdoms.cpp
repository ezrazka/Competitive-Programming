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
    }

    vector<int> disc(n, -1), low(n, -1);
    vector<bool> in_stack(n);
    vector<int> vans(n);
    int timer = 0, comp = 0;
    stack<int> st;
    auto dfs = [&](auto self, int node) -> void {
        st.push(node);
        disc[node] = low[node] = timer++;
        in_stack[node] = true;
        for (int child : adj[node]){
            if (disc[child] == -1){
                self(self, child);
                low[node] = min(low[node], low[child]);
            } else if (in_stack[child]){
                low[node] = min(low[node], disc[child]);
            }
        }
        if (disc[node] == low[node]){
            comp++;
            while(st.top() != node){
                vans[st.top()] = comp;
                in_stack[st.top()] = false;
                st.pop();
            } 
            vans[st.top()] = comp;
            in_stack[st.top()] = false;
            st.pop();
        }
    };

    for (int i = 0; i < n; i++){
        if (disc[i] == -1){
            dfs(dfs, i);
        }
    }

    cout << comp << '\n';
    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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