#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, x, y; cin >> n >> x >> y; x--, y--;

    if (n % 2 == 0 && (y - x) % 2 == 1){
        for (int i = 0; i < n; i++){
            cout << (i & 1) << " \n"[i == n - 1];
        }
    } else {
        vector<int> vans(n);
        vans[x] = 2;
        for (int i = 1; i < n; i++){
            vans[(x + i) % n] = i & 1;
        }
        for (int i = 0; i < n; i++){
            cout << vans[i] << " \n"[i == n - 1];
        }
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