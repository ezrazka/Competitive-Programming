#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> w(n), h(n);
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++){
        cin >> w[i] >> h[i];
        mx1 = max(mx1, w[i]);
        mx2 = max(mx2, h[i]);
    }

    cout << 2 * (mx1 + mx2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}