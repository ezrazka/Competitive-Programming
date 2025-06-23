#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int w, h, a, b; cin >> w >> h >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    // bool ok = true;
    // if (abs(x1 - x2) < a && abs(y1 - y2) % b != 0) ok = false;
    // if (abs(y1 - y2) < b && abs(x1 - x2) % a != 0) ok = false;
    // cout << (ok ? "Yes\n" : "No\n");
    bool ok = (x1 - x2) % a == 0 && (y1 - y2) % b == 0;
    if ((x1 - x2) % a == 0 && x1 != x2) ok = true;
    if ((y1 - y2) % b == 0 && y1 != y2) ok = true;
    cout << (ok ? "Yes\n" : "No\n");
    // ....BBB
    // ....BBB
    // .......
    // AAA....
    // AAA....

    // ...BB..
    // ...BB..
    // .......
    // .......
    // AA.....
    // AA.....

    // ...BB..
    // ...BB..
    // .......
    // .......
    // AA.....
    // AA.....
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}