#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int binpow(int a, int b, int m){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> next(n);
    for (int i = 0; i < n; i++){
        int j; cin >> j; j--;
        next[i] = j;
    }
    // 1 -> 0
    // 2 -> 1
    // 3 -> 3
    // 4 -> 2
    // 5 -> none

    vector<bool> vis(n);
    vector<int> vans(n);
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            vis[i] = true;
            vector<int> cycle = {i};
            int cur = next[i];
            while (cur != i){
                vis[cur] = true;
                cycle.push_back(cur);
                cur = next[cur];
            }

            int sz = cycle.size();
            for (int j = 0; j < sz; j++){
                vans[cycle[j]] = cycle[(j + binpow(2, k, sz)) % sz];
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] + 1 << " \n"[i == n - 1];
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