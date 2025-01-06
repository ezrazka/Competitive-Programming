#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int l, r; cin >> l >> r;
    // maximum disjoint pair + random number

    int a = 0, b = 0, c = 0;
    for (int bit = 29; bit >= 0; bit--){
        if (l <= r / (1 << bit) * (1 << bit) - 1 && (r & (1 << bit))){
            a = r / (1 << bit) * (1 << bit) - 1, b = r / (1 << bit) * (1 << bit), c = (r / (1 << bit) * (1 << bit) + 1 > r ? r / (1 << bit) * (1 << bit) - 2 : r / (1 << bit) * (1 << bit) + 1);
            break;
        }
    }

    cout << a << ' ' << b << ' ' << c << '\n';
    // cout << (a ^ b) + (a ^ c) + (b ^ c) << '\n';

    // for each bit, must have 1 or 2
    /*
        6
        30
        6
        62
        30
        126
        30
        2147483646

        6
        18
        6
        34
        18
        78
        30
        2147483646

    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}