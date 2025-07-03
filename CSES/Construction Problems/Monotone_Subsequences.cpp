#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;

    if (k * k < n){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> vans(n);
    iota(vans.begin(), vans.end(), 1);
    for (int i = 0; i < n; i += k){
        reverse(vans.begin() + i, vans.begin() + min(n, i + k));
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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