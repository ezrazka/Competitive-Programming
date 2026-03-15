#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (int _ = 0; _ < n - 1; _++){
        int u, v, x, y; cin >> u >> v >> x >> y; u--, v--;
        if (x < y) adj[u].push_back(v), indegree[v]++;
        else adj[v].push_back(u), indegree[u]++;
    }

    queue<int> q;
    for (int node = 0; node < n; node++){
        if (indegree[node] == 0){
            q.push(node);
        }
    }

    vector<int> p(n);
    int cur = 1;
    while (!q.empty()){
        int node = q.front(); q.pop();
        p[node] = cur++;
        for (int child : adj[node]){
            if (--indegree[child] == 0){
                q.push(child);
            }
        }
    }
    
    for (int node = 0; node < n; node++){
        cout << p[node] << " \n"[node == n - 1];
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