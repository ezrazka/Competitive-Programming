#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, a, b; cin >> n >> a >> b;
    int c = n - a - b;

    if (c < 0 || ((a == 0) ^ (b == 0))){
        cout << "NO\n";
        return;
    }

    vector<int> vans1(n), vans2(n);
    iota(vans1.begin(), vans1.end(), 1);
    iota(vans2.begin(), vans2.end(), 1);
    rotate(vans2.begin(), vans2.begin() + a, vans2.begin() + a + b);

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        cout << vans1[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++){
        cout << vans2[i] << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}