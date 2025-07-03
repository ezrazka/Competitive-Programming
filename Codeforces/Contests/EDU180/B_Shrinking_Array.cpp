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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 1e9;
    for (int i = 0; i < n - 1; i++){
        if (abs(v[i] - v[i + 1]) <= 1) ans = min(ans, 0ll);
    }
    for (int i = 1; i < n - 1; i++){
        if ((v[i] > v[i - 1]) == (v[i] > v[i + 1])) ans = min(ans, 1ll);
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}