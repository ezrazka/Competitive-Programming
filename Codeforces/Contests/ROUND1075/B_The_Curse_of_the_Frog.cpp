#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 2e18;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int cur = 0;
    for (int i = 0; i < n; i++){
        cur += a[i] * (b[i] - 1);
    }

    if (cur >= x){
        cout << 0 << '\n';
        return;
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++){
        int need = x - cur;
        int profit = a[i] * b[i] - c[i];
        if (profit <= 0) continue;
        ans = min(ans, (need + profit - 1) / profit);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}