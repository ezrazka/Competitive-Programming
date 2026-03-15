#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    int ans = INF;
    if (abs(a - b) % 2 == 0) ans = min(ans, b);
    if (abs(b - c) % 2 == 0) ans = min(ans, c);
    if (abs(a - c) % 2 == 0) ans = min(ans, c);
    cout << ans << '\n';

    /*
    there is no -1
    proof by contradiction:
    every move will lead to a new state because it decreases the total by 1.
    assume that there is a state where we cant perform a valid move,
    the stage is exactly the ending scenario,
    so when we arent yet at the end we are always approaching it
    QED

    its always optimal to reach a = b or b = c asap
    ans is either:
        * (b - a + 1) / 2 // a = b, 
        * 

    delete 2, add 1

    0 99 100
    --------
    1 98 99
    0 98 98

    0 100 101
    ---------
    1 99 100
    0 99 99

    3 1 0
    -----
    2 0 1
    1 1 0
    0 0 1

    4 1 0
    -----
    3 0 1
    2 1 0
    1 0 1
    0 1 0

    3 2 0
    -----
    2 1 1
    1 0 2
    0 1 1
    1 0 0

    4 2 0
    -----
    3 1 1
    2 0 2
    0 1 1
    1 0 0

    7 3 0
    -----
    4 0 3 -> 3
    1 3 0 -> 3
    0 2 1 -> 1
    1 1 0 -> 1
    0 0 1 -> 0

    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}