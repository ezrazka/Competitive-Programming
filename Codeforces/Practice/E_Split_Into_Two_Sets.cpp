#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> pairs(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++){
        int u, v; cin >> u >> v; u--, v--;
        pairs[u].push_back(i);
        pairs[v].push_back(i);
        freq[u]++;
        freq[v]++;
    }

    for (int i = 0; i < n; i++){
        if (freq[i] != 2){
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < n; i++){
        adj[pairs[i][0]].push_back(pairs[i][1]);
        adj[pairs[i][1]].push_back(pairs[i][0]);
    }

    vector<int> set(n);
    bool ok = true;
    auto dfs = [&](auto self, int node, int parent) -> void {
        for (int child : adj[node]){
            if (child != parent){
                if (set[node] == set[child]) ok = false;
                if (set[child] == 0){
                    set[child] = 3 - set[node];
                    self(self, child, node);
                }
            }
        }
    };
    for (int i = 0; i < n; i++){        
        if (set[i] == 0){
            set[i] = 1;
            dfs(dfs, i, -1);
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}