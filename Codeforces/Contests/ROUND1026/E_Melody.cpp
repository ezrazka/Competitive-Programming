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
    map<int, vector<int>> a, b;
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
        a[v[i].fi].push_back(i);
        b[v[i].se].push_back(i);
    }

    auto dfs = [&](auto self, int node)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}