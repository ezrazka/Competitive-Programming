#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < m; i++){
        cin >> v[i]; v[i]--;
    }
    vector<bool> know(n);
    for (int i = 0; i < k; i++){
        int idx; cin >> idx; idx--;
        know[idx] = true;
    }

    if (k == n){
        for (int i = 0; i < m; i++){
            cout << 1;
        }
        cout << '\n';
    } else if (k == n - 1){
        for (int i = 0; i < m; i++){
            cout << !know[v[i]];
        }
        cout << '\n';
    } else {
        for (int i = 0; i < m; i++){
            cout << 0;
        }
        cout << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}