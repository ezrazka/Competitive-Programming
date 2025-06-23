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
    cout << 2 * n - 1 << '\n';
    cout << 1 << ' ' << 1 << ' ' << n << '\n';
    for (int i = 2; i <= n; i++){
        cout << i << ' ' << 1 << ' ' << i - 1 << '\n';
        cout << i << ' ' << i << ' ' << n << '\n';
    }
    /*
    1 2 3 4
    -------
    1 2 3 4
    2 1 4 3
    3 4 1 2
    4 3 2 1

    1 2 3 4 5
    ---------
    5 4 3 2 1
    1 5 4 3 2
    2 1 5 4 3
    3 2 1 5 4
    4 3 2 1 5
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