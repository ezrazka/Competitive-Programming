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

    int l = max(0ll, k - n), r = min(n, k), res = -1;
    while (l <= r){
        int mid = (l + r) / 2;

        int F = 1e9, S = 1e9;
        if (mid > 0) cout << "F " << mid << endl, cin >> F;
        if (k - mid > 0) cout << "S " << k - mid << endl, cin >> S;
        bool ok = false;
        if (F == S) ok = true;
        if (F > S){
            if (mid == n) ok = true;
            else {
                int X;
                cout << "F " << mid + 1 << endl, cin >> X;
                if (X <= S) ok = true;
            }
        }
        if (F < S){
            if (k - mid == n) ok = true;
            else {
                int X;
                cout << "S " << k - mid + 1 << endl, cin >> X;
                if (X <= F) ok = true;
            }
        }

        if (S < F){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        if (ok) res = min(F, S);
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