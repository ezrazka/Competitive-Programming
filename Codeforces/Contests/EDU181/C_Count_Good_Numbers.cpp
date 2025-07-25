#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int calc(int x){
    return x - ((x / 2 + x / 3 + x / 5 + x / 7) - (x / 6 + x / 10 + x / 14 + x / 15 + x / 21 + x / 35) + (x / 30 + x / 42 + x / 70 + x / 105) - (x / 210));
}

void solve(){
    int a, b; cin >> a >> b;
    cout << calc(b) - calc(a - 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}