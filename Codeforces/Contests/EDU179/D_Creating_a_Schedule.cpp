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
    vector<int> v(m);
    for (int i = 0; i < m; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 0, r = m - 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 6; j++){
            cout << v[((i & 1) ^ (j & 1)) ? l : r] << ' ';
        }
        cout << '\n';
        if (i & 1) l++, r--;
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