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
    vector<int> prüfer(n - 2);
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; i++){
        cin >> prüfer[i]; prüfer[i]--;
        degree[prüfer[i]]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int node = 0; node < n; node++){
        if (degree[node] == 1){
            pq.push(node);
        }
    }

    vector<pii> vans;
    for (int node : prüfer){
        int leaf = pq.top(); pq.pop();
        vans.push_back({leaf, node});
        if (--degree[node] == 1){
            pq.push(node);
        }
    }
    vans.push_back({pq.top(), n - 1});

    for (int i = 0; i < n - 1; i++){
        cout << vans[i].fi + 1 << ' ' << vans[i].se + 1 << '\n';
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