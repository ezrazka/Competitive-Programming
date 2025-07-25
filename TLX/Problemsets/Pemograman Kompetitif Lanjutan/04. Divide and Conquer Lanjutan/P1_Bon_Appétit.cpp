#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> v(4, vector<int>(n));
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < n; i++){
            cin >> v[j][i];
        }
    }

    vector<int> sums1, sums2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sums1.push_back(v[0][i] + v[1][j]);
            sums2.push_back(v[2][i] + v[3][j]);
        }
    }
    sort(sums1.begin(), sums1.end());
    sort(sums2.begin(), sums2.end());

    int ans = 0;
    for (int i = 0; i < n * n; i++){
        ans += upper_bound(sums2.begin(), sums2.end(), k - sums1[i]) - sums2.begin();
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}