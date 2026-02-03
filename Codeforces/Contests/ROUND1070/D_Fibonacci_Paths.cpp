#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    vector<vector<int>> full_adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        if (a[u] < a[v]){ // guarantees DAG
            adj[u].push_back(v);
            indegree[v]++;
        }
        full_adj[u].push_back(v);
    }
    
    queue<int> q;
    for (int node = 0; node < n; node++){
        if (indegree[node] == 0){
            q.push(node);
        }
    }

    vector<map<int, int>> sums(n);
    for (int node = 0; node < n; node++){
        for (int child : full_adj[node]){
            sums[child][a[node] + a[child]]++;
        }
    }
    
    while (!q.empty()){
        int node = q.front(); q.pop();
        
        for (int child : adj[node]){
            sums[child][a[node] + a[child]] += sums[node][a[child]];
            sums[child][a[node] + a[child]] %= MOD;
            if (--indegree[child] == 0){
                q.push(child);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (auto [sum, freq] : sums[i]){
            ans += freq;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}