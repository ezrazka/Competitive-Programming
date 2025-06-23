#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, p, k; cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            debug(a[i]);
            debug(a[j]);
            cout << (a[i] ^ a[j]) * ((a[i] * a[i]) ^ (a[j] * a[j])) % p << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}