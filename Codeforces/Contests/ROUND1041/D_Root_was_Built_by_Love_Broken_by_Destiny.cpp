#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

vector<int> fact(2e6 + 1);

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 2e6; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 2;
    vector<int> depth(n, -1);
    depth[0] = 0;
    bool done = false;
    auto dfs = [&](auto self, int node, int parent) -> void {
        int children = 0;
        for (int child : adj[node]){
            if (child != parent){
                if (depth[child] != -1){
                    ans = 0;
                    done = true;
                    return;
                }
                depth[child] = depth[node] + 1;
                self(self, child, node);
                if (done) return;
                children++;
            }
        }
        ans = (ans * fact[children]) % MOD;
    };
    dfs(dfs, 0, -1);

    int mx_depth = *max_element(depth.begin(), depth.end());
    ans = (ans * fact[(mx_depth + 1) / 2]) % MOD;

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}