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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    string ans;
    for (int i = 0; i < n / 2; i++){
        if ((i % 2 == 0) ^ (v[i] < v[(n - 1) - i])){
            ans += "RL";
        } else {
            ans += "LR";
        }
    }
    if (n & 1) ans += 'L';
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}