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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        v[i] -= n - i;
    }

    map<int, vector<int>> adj;
    for (int i = 1; i < n; i++){
        adj[v[i]].push_back(v[i] + i);
    }

    int ans = 0;
    map<int, int> vis;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()){
        int node = q.front(); q.pop();
        ans = max(ans, node);
        for (int child : adj[node]){
            if (!vis[child]){
                q.push(child);
                vis[child] = true;
            }
        }
    }
    cout << n + ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}