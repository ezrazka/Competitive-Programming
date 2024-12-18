#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> edges;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        edges.emplace_back(u, v);
    }

    for (pii edge : edges){
        if (edge.fi > edge.se) swap(edge.fi, edge.se);
        cout << edge.fi + 1 << ' ' << edge.se + 1 << '\n';
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