#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++) cin >> b[i], b[i]--;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++){
        adj[a[i]].emplace_back(b[i], i);
        adj[b[i]].emplace_back(a[i], i);
    }

    for (int i = 0; i < n; i++){
        if (adj[i].size() & 1){
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> vans;
    vector<bool> vis(n);
    vector<int> order;
    auto dfs = [&](auto self, int node) -> void {
        while (adj[node].size()){
            auto [child, id] = adj[node].back(); adj[node].pop_back();
            if (vis[id]) continue;
            vis[id] = true;
            if (node != b[id]){
                vans.push_back(id);
            }
            self(self, child);
        }
    };
    for (int i = 0; i < n; i++){
        dfs(dfs, i);
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