#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int xor_a = 0, xor_b = 0;
    for (int i = 0; i < n; i++) xor_a ^= a[i];
    for (int i = 0; i < m; i++) xor_b ^= b[i];

    if (xor_a != xor_b){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0){
                int res = a[0];
                for (int k = 1; k < m; k++){
                    res ^= b[k];
                }
                cout << res << ' ';
            } else if (i == 0){
                cout << b[j] << ' ';
            } else if (j == 0){
                cout << a[i] << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
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