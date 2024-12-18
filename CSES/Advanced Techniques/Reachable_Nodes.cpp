#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int N = 5e4;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> outdegree(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[v].push_back(u);
        outdegree[u]++;
    }

    queue<int> q;
    vector<bitset<N>> bits(n);
    for (int node = 0; node < n; node++){
        bits[node][node] = 1;
        if (outdegree[node] == 0){
            q.push(node);
        }
    }

    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int parent : adj[node]){
            bits[parent] |= bits[node];
            if (--outdegree[parent] == 0){
                q.push(parent);
            }
        }
    }

    for (int node = 0; node < n; node++){
        cout << bits[node].count() << " \n"[node == n - 1];
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