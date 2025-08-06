#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
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

void union_sets(vector<int>& parent, vector<int>& size, int a, int b){
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b){
        if (size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(){
    int m; cin >> m;
    int n = 2 * m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        edges.push_back({u, v});
    }

    vector<int> parent(n), size(n);
    for (int i = 0; i < n; i++){
        make_set(parent, size, i);
    }

    vector<int> vans;
    for (int i = 0; i < m; i++){
        auto [u, v] = edges[i];
        if (find_set(parent, u) == find_set(parent, v)){
            continue;
        }
        union_sets(parent, size, u, v);
        vans.push_back(i);
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] + 1 << " \n"[i == vans.size() - 1];
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