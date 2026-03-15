#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];

    int total = (f[0] + f[n - 1]) / (n - 1);

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n - 1; i++){
        a[i] = ((f[i + 1] - f[i]) + total) / 2 - sum;
        sum += a[i];
    }
    a[n - 1] = total - accumulate(a.begin(), a.end(), 0ll);

    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
    }

    /*
    0 1 2 3 4
    1 0 1 2 3
    2 1 0 1 2
    3 2 1 0 1
    4 3 2 1 0
    *
    a[0]
    a[1]
    a[2]
    a[3]
    a[4]
    =
    f[0]
    f[1]
    f[2]
    f[3]
    f[4]

    Observations:
    * f(1) + f(n) == (n - 1) * sum(a)
    -4 -2 0 2 4
    -2 -1 0 1 2
    -1 0 1 2 3
    0 1 2 3 4
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