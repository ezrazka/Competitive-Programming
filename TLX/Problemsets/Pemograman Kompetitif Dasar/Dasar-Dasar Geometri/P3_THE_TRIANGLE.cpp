#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a[3];
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a, a + 3);
    cout << max(0ll, a[2] - a[1] - a[0] + 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}