#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, h; cin >> n >> h;

    /*
    (-b +- sqrt(b^2 - 4ac)) / (2a)
    
    res(res + 1)/2 <= n
    1/2 * res^2 + 1/2 * res - n <= 0

    ((-1/2) +- sqrt((1/2)^2 - 4(1/2)(-n))) / (2(1/2))
    = floor(-1/2 + sqrt(1/4 + 2h))
    */
    {
        int res = min(h, (int) (-1 + sqrtl(1 + 8 * n)) / 2);
        if (res < h){
            int rem = n - (res * (res + 1) / 2);
            cout << res + (rem > 0) << '\n';
            return;
        }
    }

    /*
    (-b +- sqrt(b^2 - 4ac)) / (2a)
    
    res * res - h * (h - 1) / 2 - n <= 0
    a = 1, b = 0, c = -h(h - 1)/2 - n

    (-(0) +- sqrt((0)^2 - 4(1)(-h(h - 1)/2 - n))) / (2(1))
    sqrt(2h(h-1) + 4n)/2
    */
    int height = sqrtl(2 * h * (h - 1) + 4 * n) / 2;
    int res = 2 * height - h;

    int rem = n - (height * height - h * (h - 1) / 2);
    cout << res + (rem + height - 1) / height << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}