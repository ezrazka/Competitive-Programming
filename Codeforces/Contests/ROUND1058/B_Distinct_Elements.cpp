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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> vans(n, -1);
    vans[0] = 1;
    cout << vans[0] << ' ';
    for (int i = 1; i < n; i++){
        int diff = v[i] - v[i - 1];
        vans[i] = (i - diff == -1 ? i + 1 : vans[i - diff]);
        cout << vans[i] << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}