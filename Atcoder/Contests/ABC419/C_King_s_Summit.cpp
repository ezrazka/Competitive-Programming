#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int mn_x = *min_element(x.begin(), x.end());
    int mx_x = *max_element(x.begin(), x.end());
    int mn_y = *min_element(y.begin(), y.end());
    int mx_y = *max_element(y.begin(), y.end());
    cout << max((mx_x - mn_x + 1) / 2, (mx_y - mn_y + 1) / 2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}