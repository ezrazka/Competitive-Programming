#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a < b){
        swap(a, b);
        swap(x, y);
    }

    int mn = (a * (x - 1) + gcd(a, b)) / b, mx = (a * (x + 1) - gcd(a, b) + b - 1) / b;
    // if (mx - mn > 2){
    //     cout << "Idk\n";
    //     return;
    // }
    cout << (mn <= y && y <= mx ? "Yes\n" : "No\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}