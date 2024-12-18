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
    vector<vector<int>> adj(1 << (n - 1));
    for (int node = 0; node < (1 << (n - 1)); node++){
        adj[node].push_back(node >> 1 | (1 << (n - 2)));
        adj[node].push_back(node >> 1);
    }

    if (n == 1){
        cout << "01\n";
        return;
    }

    string ans;
    auto dfs = [&](auto self, int node) -> void {
        while (!adj[node].empty()){
            int child = adj[node].back();
            adj[node].pop_back();
            self(self, child);
        }
        ans += '0' + !!(node & (1 << (n - 2)));
    };
    dfs(dfs, 0);
    for (int i = 0; i < n - 2; i++){
        ans += '0';
    }
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}