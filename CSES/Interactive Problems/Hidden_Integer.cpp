#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int l = 1, r = 1e9, res = -1;
    while (l <= r){
        int mid = (l + r) / 2;

        cout << "? " << mid << endl;
        string s; cin >> s;

        if (s == "YES"){
            l = mid + 1;
        } else {
            r = mid - 1;
            res = mid;
        }
    }
    cout << "! " << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}