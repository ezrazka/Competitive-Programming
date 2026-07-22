#include <bits/stdc++.h>
using namespace std;
 
// Macros
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define f first
#define s second
#define endl '\n'
 
// Debugging
#define debug(x) cout<<'('<<(#x)<<" : "<<(x)<<')'<<endl
#define debughere cout<<"HERE"<<endl
 
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> c >> b >> a; a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
 
    vi dist(n, 1e18);
 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()){
        auto [weight, node] = pq.top();
        pq.pop();
 
        if (dist[node] < weight){
            continue;
        }
 
        for (auto [child, weight2] : adj[node]){
            if (dist[node] + weight2 < dist[child]){
                dist[child] = dist[node] + weight2;
                pq.push({dist[child], child});
            }
        }
    }
 
    for (int i = 1; i < n; i++){
        cout << (dist[i] == 1e18 ? -1 : dist[i]) << '\n';
    }
    cout << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
