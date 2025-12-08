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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i], v[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vans(n);
    map<int, int> mp;
    for (int node = 0; node < n; node++){
        mp[v[node]]++;
        for (int child : adj[node]){
            mp[v[child]]++;
        }
        for (auto [key, val] : mp){
            if (val >= 2){
                vans[key] = true;
            }
        }
        mp.clear();
    }

    for (int i = 0; i < n; i++){
        cout << vans[i];
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}