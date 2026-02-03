#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, d, k; cin >> n >> d >> k;

    if (n == 2){
        if (d > 1){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << "1 2\n";
        }
        return;
    }

    if (k < 2 || d + 1 > n){
        cout << "NO\n";
        return;
    }

    vector<pair<int, int>> vans;
    for (int node = 0; node < d; node++){
        vans.emplace_back(node, node + 1);
    }

    int cur = d + 1;

    queue<array<int, 3>> q; // {node, depth left, degrees left};
    for (int node = 0; node <= d; node++){
        int depth_left = min(node, d - node);
        int degrees_left = k - (depth_left == 0 ? 1 : 2);
        q.push({node, depth_left, degrees_left});
    }
    while (!q.empty() && cur < n){
        auto [node, depth_left, degrees_left] = q.front(); q.pop();
        if (depth_left == 0 || degrees_left == 0) continue;
        q.push({node, depth_left, degrees_left - 1});
        q.push({cur, depth_left - 1, k - 1});
        vans.emplace_back(node, cur);
        cur++;
    }

    if (cur < n){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++){
            cout << vans[i].first + 1 << ' ' << vans[i].second + 1 << '\n';
        }
    }

    /*
    Observations:
    * Edge Case: n == 2, (n == k + 1 ? "YES\n" : "NO\n");
    * Must fulfill n >= k + 1
    * d >= 2
    Conditions:
        * d >= 
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}