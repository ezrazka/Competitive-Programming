#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const ld EPS = 1e-12;

void solve(){
    ld xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
    ld a, b, r; cin >> a >> b >> r;

    // (x - a)^2 + (y - b)^2 = r^2

    ld ans = 1e10;
    { // top arc
        ld low = a - r, high = a + r, res;
        while (high - low > EPS){
            ld x1 = low + (high - low) / 3;
            ld x2 = high - (high - low) / 3;

            ld y1 = b + sqrt(r * r - (x1 - a) * (x1 - a));
            ld y2 = b + sqrt(r * r - (x2 - a) * (x2 - a));

            ld f1 = sqrt(abs(xa - x1) * abs(xa - x1) + abs(ya - y1) * abs(ya - y1)) + sqrt(abs(xb - x1) * abs(xb - x1) + abs(yb - y1) * abs(yb - y1));
            ld f2 = sqrt(abs(xa - x2) * abs(xa - x2) + abs(ya - y2) * abs(ya - y2)) + sqrt(abs(xb - x2) * abs(xb - x2) + abs(yb - y2) * abs(yb - y2));;

            if (f1 > f2){
                low = x1;
            } else {
                high = x2;
            }
            res = min(f1, f2);
        }
        ans = min(ans, res);
    }
    { // bottom arc
        ld low = a - r, high = a + r, res;
        while (high - low > EPS){
            ld x1 = low + (high - low) / 3;
            ld x2 = high - (high - low) / 3;

            ld y1 = b - sqrt(r * r - (x1 - a) * (x1 - a));
            ld y2 = b - sqrt(r * r - (x2 - a) * (x2 - a));

            ld f1 = sqrt(abs(xa - x1) * abs(xa - x1) + abs(ya - y1) * abs(ya - y1)) + sqrt(abs(xb - x1) * abs(xb - x1) + abs(yb - y1) * abs(yb - y1));
            ld f2 = sqrt(abs(xa - x2) * abs(xa - x2) + abs(ya - y2) * abs(ya - y2)) + sqrt(abs(xb - x2) * abs(xb - x2) + abs(yb - y2) * abs(yb - y2));;

            if (f1 > f2){
                low = x1;
            } else {
                high = x2;
            }
            res = min(f1, f2);
        }
        ans = min(ans, res);
    }
    cout << fixed << setprecision(9) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}