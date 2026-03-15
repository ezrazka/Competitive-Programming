#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void make_set(vector<int>& parent, vector<int>& size, int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(vector<int>& parent, int v){
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vector<int>& parent, vector<int>& size, auto& pq, int a, int b){
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b){
        if (size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        while (!pq[b].empty()) pq[a].push(pq[b].top()), pq[b].pop();
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < m; _++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n), size(n);
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> pq(n);
    for (int node = 0; node < n; node++){
        make_set(parent, size, node);
        for (int child : adj[node]){
            pq[node].emplace(a[child], child);
        }
    }
    
    vector<int> components;
    for (int node = 0; node < n; node++){
        if (a[node] == 0){
            components.push_back(node);
        }
    }
    
    int sets = n;
    for (int comp : components){
        comp = find_set(parent, comp);
        while (!pq[comp].empty() && size[comp] >= pq[comp].top().first){
            int child = pq[comp].top().second; pq[comp].pop();
            if (comp != find_set(parent, child)){
                union_sets(parent, size, pq, comp, child);
                sets--;
            }
        }
    }
    cout << (sets == 1 ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}