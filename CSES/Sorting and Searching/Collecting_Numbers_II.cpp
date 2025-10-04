#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        pos[v[i]] = i;
    }

    int res = 1;
    for (int i = 1; i <= n - 1; i++){
        if (pos[i + 1] < pos[i]) res++;
    }

    while (q--){
        int i, j; cin >> i >> j;
        {
            set<int> st = {v[i], v[i] + 1, v[j], v[j] + 1};
            for (int val : st){
                if (val - 1 < 1 || val > n) continue;
                if (pos[val] < pos[val - 1]){
                    res--;
                }
            }
        }
        {
            swap(v[i], v[j]);
            swap(pos[v[i]], pos[v[j]]);
        }
        {
            set<int> st = {v[i], v[i] + 1, v[j], v[j] + 1};
            for (int val : st){
                if (val - 1 < 1 || val > n) continue;
                if (pos[val] < pos[val - 1]){
                    res++;
                }
            }
        }
        cout << res << '\n';
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