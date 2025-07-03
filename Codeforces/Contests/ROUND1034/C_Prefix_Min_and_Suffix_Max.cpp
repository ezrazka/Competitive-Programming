#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    
    vector<int> pref_min(n);
    vector<int> suff_max(n);
    pref_min[0] = v[0];
    for (int i = 1; i < n; i++){
        pref_min[i] = min(pref_min[i - 1], v[i]);
    }
    suff_max[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suff_max[i] = max(suff_max[i + 1], v[i]);
    }

    string ans;
    for (int i = 0; i < n; i++){
        ans += '0';
    }
    for (int i = 0; i < n; i++){
        if ((i == 0 || pref_min[i - 1] > v[i]) || (i == n - 1 || suff_max[i + 1] < v[i])){
            ans[i] = '1';
        }
    }
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