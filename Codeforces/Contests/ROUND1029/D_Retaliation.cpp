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

    if (v[0] > v[1]){
        reverse(v.begin(), v.end());
    }

    for (int i = 1; i < n - 1; i++){
        if (v[i + 1] - v[i] != v[1] - v[0]){
            cout << "NO\n";
            return;
        }
    }

    cout << (v[0] >= v[1] - v[0] && (v[0] - (v[1] - v[0])) % (n + 1) == 0 ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}