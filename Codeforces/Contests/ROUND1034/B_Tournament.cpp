#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, j, k; cin >> n >> j >> k; j--;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    if (v[j] == mx){
        cout << (k >= 1 ? "YES\n" : "NO\n");
    } else {
        cout << (k >= 2 ? "YES\n" : "NO\n");
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