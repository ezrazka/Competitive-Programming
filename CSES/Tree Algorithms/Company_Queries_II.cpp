#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int u = 1; u < n; u++){
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                depth[child] = depth[node] + 1;
                self(self, child, node);
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<int> log2(2 * n);
    log2[0] = -1, log2[1] = 0;
    for (int i = 2; i <= 2 * n - 1; i++){
        log2[i] = log2[i / 2] + 1;
    }

    vector<vector<pii>> sparse_table(2 * n - 1, vector<pii>(log2[2 * n - 1] + 1, {1e9, -1}));
    vector<int> tin(n, -1);
    int timer = 0;
    auto euler_tour = [&](auto self, int node, int parent) -> void {
        sparse_table[timer][0] = {depth[node], node};
        tin[node] = timer++;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                sparse_table[timer][0] = {depth[node], node};
                timer++;
            }
        }
    };
    euler_tour(euler_tour, 0, -1);

    for (int bit = 1; bit <= log2[2 * n - 1]; bit++){
        for (int i = 0; i < 2 * n - 1; i++){
            if (i + (1 << bit) <= 2 * n - 1){
                sparse_table[i][bit] = min(sparse_table[i][bit - 1], sparse_table[i + (1 << bit - 1)][bit - 1]);
            }
        }
    }

    while (q--){
        int a, b; cin >> a >> b; a--, b--;
        int l = tin[a], r = tin[b];
        if (l > r) swap(l, r);

        int bit = log2[r - l + 1];
        cout << min(sparse_table[l][bit], sparse_table[r - (1 << bit) + 1][bit]).se + 1 << '\n';
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