#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int x, y, k; cin >> x >> y >> k;
    int z = min(x, y);
    cout << 0 << ' ' << 0 << ' ' << z << ' ' << z << '\n';
    cout << z << ' ' << 0 << ' ' << 0 << ' ' << z << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}