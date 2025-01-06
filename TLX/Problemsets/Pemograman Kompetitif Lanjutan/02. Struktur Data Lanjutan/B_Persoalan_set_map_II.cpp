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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    set<int> complement;
    for (int i = 1; i <= k + 1; i++){
        complement.insert(i);
    }
    map<int, int> mp;
    for (int i = 0; i < k; i++){
        mp[v[i]]++;
        if (mp[v[i]] == 1 && v[i] <= k + 1){
            complement.erase(v[i]);
        }
    }
    cout << *complement.begin() << '\n';
    for (int i = k; i < n; i++){
        mp[v[i - k]]--;
        if (mp[v[i - k]] == 0 && v[i - k] <= k + 1){
            complement.insert(v[i - k]);
        }
        mp[v[i]]++;
        if (mp[v[i]] == 1 && v[i] <= k + 1){
            complement.erase(v[i]);
        }
        cout << *complement.begin() << '\n';
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