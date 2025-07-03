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
    
    vector<int> vans(n);
    for (int i = n; i >= 1 && k > 0; i--){
        int shift = min(k, i - 1);
        vans[(i - shift) + (n - i) - 1] = i;
        k -= shift;
    }
    for (int i = 0, j = 1; i < n; i++){
        if (vans[i] == 0){
            vans[i] = j++;
        }
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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