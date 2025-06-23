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
    sort(v.begin(), v.end());

    if ((v[0] + v[n - 1]) % 2 == 0){
        cout << 0 << '\n';
        return;
    }

    int ans = 1e18;
    for (int i = 0; i < n - 1; i++){
        if ((v[i] & 1) != (v[i + 1] & 1)){
            ans = min(ans, i + 1);
            break;
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++){
        if ((v[i] & 1) != (v[i + 1] & 1)){
            ans = min(ans, i + 1);
            break;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}