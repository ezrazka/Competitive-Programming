#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(int i, int x){
    cout << "? " << i << ' ' << x << endl;
    int res; cin >> res;
    return res;
}

void answer(int x){
    cout << "! " << x << endl;
}

void solve(){
    int n; cin >> n;
    int m = __lg(n) + 1;

    int ans = 0;
    vector<bool> vis(n + 1);
    for (int j = 0; j < m; j++){
        vector<int> idxs[2];
        for (int i = 1; i <= n - 1; i++){
            if (vis[i]) continue;
            int x = query(i, (1 << j));
            idxs[x].push_back(i);
        }
        
        int bits = 0;
        for (int i = 1; i <= n; i++){
            if (i % (1 << (j + 1)) == (ans | (1 << j))){
                bits++;
            }
        }
        
        bool ok1 = (idxs[1].size() == bits);
        for (int i : idxs[ok1]){
            vis[i] = true;
        }
        ans |= ((!ok1) << j);
    }
    answer(ans);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}