#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int p, q; cin >> p >> q;

    if (p >= q || p * 3 < 2 * q){
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }

    /*
    a/b > 1/3 - subtract a

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