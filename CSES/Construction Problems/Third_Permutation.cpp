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
    vector<int> a(n), b(n);
    vector<pair<int, int>> pairs(n, {-1, -1});
    for (int i = 0; i < n; i++) cin >> a[i], pairs[a[i] - 1].fi = i;
    for (int i = 0; i < n; i++) cin >> b[i], pairs[b[i] - 1].se = i;
    sort(pairs.begin(), pairs.end());

    if (n == 2){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<vector<int>> two_cycles;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++){
        if (!vis[pairs[i].fi]){
            vector<int> cycle;
            int cur = pairs[i].fi;
            while (!vis[cur]){
                vis[cur] = true;
                cycle.push_back(cur);
                cur = pairs[cur].se;
            }
            if (cycle.size() == 2){
                two_cycles.push_back(cycle);
            }
        }
    }
    
    vector<int> vans(n);
    for (int i = 0; i < n; i++){
        vans[pairs[i].se] = b[pairs[i].fi];
    }

    if (two_cycles.size() == 1){
        for (int i = 0, j = 0; i < n && j < 2; i++){
            if (i == two_cycles[0][0] || i == two_cycles[0][1]){
                continue;
            }
            swap(vans[i], vans[pairs[two_cycles[0][j]].se]);
            j++;
        }
    } else {
        for (int i = 0; i < (int) two_cycles.size() - 1; i++){
            swap(vans[two_cycles[i][0]], vans[two_cycles[i + 1][0]]);
            swap(vans[two_cycles[i][1]], vans[two_cycles[i + 1][1]]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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