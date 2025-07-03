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

    cout << "? " << 1 << endl;
    char c; cin >> c;
    int good_parity = (c == 'R') ^ (1 & 1);
    int l = 2, r = n, res = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        
        cout << "? " << mid << endl;
        char c; cin >> c;
        int parity = (c == 'R') ^ (mid & 1);

        if (parity == good_parity){
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
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