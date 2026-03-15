#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n), adjr(n);
    vector<vector<bool>> reachable(n, vector<bool>(n));
    bool ok = true;
    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            char c; cin >> c;
            if (u == v){
                if (c == '0') ok = false;
                continue;
            }
            if (c == '1'){
                adj[u].push_back(v);
                adjr[v].push_back(u);
                reachable[u][v] = true;
            }
        }
    }

    if (!ok){
        cout << "No\n";
        return;
    }

    for (int node = 0; node < n; node++){
        for (int child : adj[node]){
            for (int parent : adjr[node]){
                if (!reachable[parent][child]){
                    cout << "No\n";
                    return;
                }
                reachable[parent][child] = false;
            }
        }
    }

    vector<vector<int>> adj2(n);
    vector<int> indegree(n);
    for (int node = 0; node < n; node++){
        for (int child = 0; child < n; child++){
            if (reachable[node][child]){
                adj2[child].push_back(node);
                indegree[node]++;
            }
        }
    }

    queue<int> q;
    for (int node = 0; node < n; node++){
        if (indegree[node] == 0){
            q.push(node);
        }
    }

    vector<pair<int, int>> vans;
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int child : adj2[node]){
            vans.emplace_back(child, node);
            if (--indegree[child] == 0){
                q.push(child);
            }
        }
    }

    if (vans.size() < n - 1){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (int i = 0; i < n - 1; i++){
        cout << vans[i].first + 1 << ' ' << vans[i].second + 1 << '\n';
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