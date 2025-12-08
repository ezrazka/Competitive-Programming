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
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++){
        mx = max(mx, v[i]);
        if (i & 1) v[i] = mx;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i += 2){
        int new_val = v[i];
        if (i - 1 >= 0) new_val = min(new_val, v[i - 1] - 1);
        if (i + 1 < n) new_val = min(new_val, v[i + 1] - 1);
        ans += max(0ll, v[i] - new_val);
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