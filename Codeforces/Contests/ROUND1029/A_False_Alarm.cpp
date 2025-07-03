#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int l = -1, r = -2;
    for (int i = 0; i < n; i++){
        if (v[i] == 1){
            l = i;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        if (v[i] == 1){
            r = i;
        }
    }

    cout << (r - l + 1 <= x ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}