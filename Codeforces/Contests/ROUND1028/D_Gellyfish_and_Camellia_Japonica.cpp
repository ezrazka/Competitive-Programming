#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<pii> b(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        b[i] = {x, x};
    }

    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    for (int i = q - 1; i >= 0; i--){
        auto [x, y, z] = queries[i];
        if (x == y && y == z) continue;
    }
    /*
    check operations in reverse order

    cases:
    if x == y == z: do nothing
    elif x == z: (b[z] <= b[y] ? b[z] ∈ [b[y], 1e9] : return -1)
    elif y == z: (b[z] <= b[x] ? b[z] ∈ [b[x], 1e9] : return -1)
    else: (b[z] == min(b[x], b[y]) ? b[z] ∈ [0, 1e9] : return -1)
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}