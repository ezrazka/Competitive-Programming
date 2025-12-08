#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    bool ok = true;
    for (int bit = 0; bit < 30; bit++){
        int cnt = 0;
        for (int i = 0; i < 3; i++){
            if (a[i] & (1 << bit)) cnt++;
        }
        if (cnt == 2) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}