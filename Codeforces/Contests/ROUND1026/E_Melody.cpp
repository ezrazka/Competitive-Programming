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
    vector<pair<int, int>> v(n);
    vector<int> a, b;
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
        a.push_back(v[i].fi);
        b.push_back(v[i].se);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int na = a.size(), nb = b.size();

    for (int i = 0; i < n; i++){
        v[i].fi = lower_bound(a.begin(), a.end(), v[i].fi) - a.begin();
        v[i].se = lower_bound(b.begin(), b.end(), v[i].se) - b.begin();
    }

    vector<vector<pair<int, int>>> adj(na + nb);
    for (int i = 0; i < n; i++){
        adj[v[i].fi].push_back({na + v[i].se, i});
        adj[na + v[i].se].push_back({v[i].fi, i});
    }

    int odds = 0;
    int start = 0;
    for (int i = 0; i < na + nb; i++){
        if (adj[i].size() & 1){
            odds++;
            start = i;
        }
    }

    bool is_eulerian_circuit = (odds == 0 || odds == 2);
    if (!is_eulerian_circuit){
        cout << "NO\n";
        return;
    }

    vector<bool> vis(n);
    vector<int> eulerian_path;
    auto dfs = [&](auto self, int node) -> void {
        while (!adj[node].empty()){
            auto [child, id] = adj[node].back();
            if (!vis[id]){
                vis[id] = true;
                adj[node].pop_back();
                self(self, child);
                eulerian_path.push_back(id);
            } else {
                adj[node].pop_back();
            }
        }
    };
    dfs(dfs, start);
    reverse(eulerian_path.begin(), eulerian_path.end());

    bool is_eulerian_path = (eulerian_path.size() == n);
    if (!is_eulerian_path){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        cout << eulerian_path[i] + 1 << " \n"[i == n - 1];
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