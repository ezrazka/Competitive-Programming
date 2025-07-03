#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int leaves = 0;
    for (int node = 1; node < n; node++){
        leaves += (adj[node].size() == 1);
    }

    if (leaves == 1){
        cout << binpow(2, n) << '\n';
        return;
    } else if (leaves >= 3){
        cout << 0 << '\n';
        return;
    }

    vector<int> sz(n);
    int x = -1, y = -1;
    auto dfs = [&](auto self, int node, int parent) -> void {
        sz[node] = 1;
        for (int child : adj[node]){
            if (child != parent){
                self(self, child, node);
                sz[node] += sz[child];
            }
        }
        
        if (adj[node].size() + (node == 0) != 3) return;

        for (int child : adj[node]){
            if (child != parent){
                if (x == -1) x = sz[child];
                else y = sz[child];
            }
        }
    };
    dfs(dfs, 0, -1);

    if (x > y) swap(x, y);

    cout << (binpow(2, n - x - y) * (binpow(2, y - x) + binpow(2, max(0ll, y - x - 1)))) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}