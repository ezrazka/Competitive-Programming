#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    if (n == 2){
        cout << -1 << '\n';
        return;
    }

    if (n == 3){
        cout << 1 << ' ' << 3 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        return;
    }

    if (n == 5){
        cout << 1 << ' ' << 2 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 3 << ' ' << 4 << '\n';
        cout << 1 << ' ' << 5 << '\n';
        return;
    }
    
    if (n == 6){
        cout << 1 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 3 << '\n';
        cout << 2 << ' ' << 4 << '\n';
        cout << 1 << ' ' << 5 << '\n';
        cout << 3 << ' ' << 6 << '\n';
        return;
    }

    if (n % 2 == 0){
        for (int i = 1; i <= n; i++){
            if (i == 2) continue;
            if (i == n - 4) cout << i << ' ' << 1 << '\n';
            else cout << i << ' ' << 2 << '\n';
        }
    } else {
        for (int i = 1; i <= n; i++){
            if (i == 2) continue;
            if (i == 5) cout << i << ' ' << 3 << '\n';
            else if (i == n) cout << i << ' ' << 3 << '\n';
            else cout << i << ' ' << 2 << '\n';
        }
    }

    /*
    if n is even:
        let x^2 = 4 * {sum of odd numbers}
    {sum from 1 to n} = 2 * {sum of odd numbers} + (n / 2)
    connect all numbers with 2
    we are up n - 4
    so, we can connect n - 4 with 1 instead of 2
    edge case: n = 2, n = 6

    if n is odd:
        let x^2 = 4 * {sum of odd numbers}
    {sum from 1 to n} = 2 * {sum of odd numbers} + ((n + 1) / 2) - (n + 1)
    connect all numbers with 2
    we are down (n + 1) - 2(n + 1) - 4 -> we are up n + 5
    and we can connect 5 with 3 instead of 2
    and we can connect n with 3 instead of 2
    edge case: n = 3, n = 5
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