#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int d(int n){
    int res = 0;
    while (n){
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve(){
    int x; cin >> x;

    int ans = 0;
    for (int y = x; y <= x + 100; y++){
        if (y - d(y) == x){
            ans++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}