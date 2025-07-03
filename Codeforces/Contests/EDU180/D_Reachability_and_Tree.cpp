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
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    vector<int> children(n);
    vector<pii> vans;
    int flip = -1;
    bool reverse = false;
    auto dfs = [&](auto self, int node, int parent) -> void {
        int childs = 0;
        for (int child : adj[node]){
            if (child != parent){
                childs++;
            }
        }
        children[node] = childs;
        if (flip == -1 && parent != -1 && (parent == 0 && children[parent] == 2 || parent != 0 && children[parent] == 1)){
            swap(vans.back().fi, vans.back().se);
            flip = node;
        }
        if (node == flip) reverse = true;
        for (int child : adj[node]){
            if (child != parent){
                depth[child] = depth[node] + 1;
                if (reverse ^ (depth[child] & 1)){
                    vans.push_back({node, child});
                } else {
                    vans.push_back({child, node});
                }
                self(self, child, node);
            }
        }
        if (node == flip) reverse = false;
    };
    dfs(dfs, 0, -1);

    if (flip == -1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto [x, y] : vans){
        cout << x + 1 << ' ' << y + 1 << '\n';
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