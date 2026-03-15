#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;

    if (!(n <= k && k <= 2 * n - 1)){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int remove = (2 * n - 1) - k;
    for (int i = n; i >= n - remove + 1; i--){
        cout << i << ' ' << i << ' ';
    }

    if (n - remove == 0){
        cout << '\n';
        return;
    }

    if (n - remove == 1){
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    int a = 1, b = 2;
    cout << 1 << ' ' << 2 << ' ';
    for (int i = 3; i <= n - remove; i++){
        cout << i << ' ' << a << ' ';
        a = b;
        b = i;
    }
    cout << a << ' ' << b << '\n';
    /*
    lower bound is always n
    upper bound is always 2n - 1

    1 2 3 1 4 2 5 3 4 5 -> 9
    5 5 1 2 3 1 4 2 3 4 -> 8
    5 5 4 4 1 2 3 1 2 3 -> 7

    for even: 3/2n
    for odd: n + ceil(n / 2)
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