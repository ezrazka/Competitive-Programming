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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int product = 0;
    for (int i = 0; i < n; i++){
        product ^= v[i];
    }

    cout << (product % 4 ? "first\n" : "second\n");

    /*
    0: 0
    1: 1
    2: 2
    3: 3
    4: 0
    5: 1
    6: 2
    7: 3
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