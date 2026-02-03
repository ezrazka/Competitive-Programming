#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t; s--, t--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, -1);
    vector<vector<int>> ways(n, vector<int>(2, 0));
    {
        vector<queue<int>> q(2);
        dist[s] = 0;
        ways[s][0] = 1;
        q[0].push(s);
        while (!q[0].empty() || !q[1].empty()){
            if (q[0].empty() || !q[1].empty() && q[0].back() > q[1].back()){
                int node = q[1].front(); q[1].pop();
                for (int child : adj[node]){
                    if (dist[node] + 1 == dist[child]){
                        ways[child][1] += ways[node][1];
                        ways[child][1] %= MOD;
                    }
                }
            } else {
                int node = q[0].front(); q[0].pop();
                for (int child : adj[node]){
                    if (dist[child] == -1){
                        dist[child] = dist[node] + 1;
                        q[0].push(child);
                        q[1].push(child);
                    }
                    if (dist[node] + 1 == dist[child]){
                        ways[child][0] += ways[node][0];
                        ways[child][0] %= MOD;
                    }
                    if (dist[node] + 1 == dist[child] + 1){
                        ways[child][1] += ways[node][0];
                        ways[child][1] %= MOD;
                    }
                }
            }
        }
    }
    cout << (ways[t][0] + ways[t][1]) % MOD << '\n';

    /*
    Given an undirected connected graph (no self-cycles, no multiple edges),
    count the number of paths length min_dist and min_dist + 1 MOD 1e9+7

    Case 1 (count all shortest paths):
        Done (fairly) trivially with BFS + DP
    Case 2 (count all shortest + 1 paths):
        Observations:
        * All such paths include two adjacent nodes apart of a shortest path,
          with a single node diversion
        
        We will check all adjacent nodes for being in a shortest path by checking if:
            dist_from_start[u] + dist_from_end[v] == min_dist

        Then we will count how many possible diversions can be made by checking
        the number of nodes neighboring both u and v
        This can be done via optimizing O(n^2) to O(n log n), by using a map
        -> 
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}