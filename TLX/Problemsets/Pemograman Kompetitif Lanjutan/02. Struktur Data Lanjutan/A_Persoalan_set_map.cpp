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

    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++){
        mp[v[i]]++;
    }
    cout << mp.size() << '\n';
    for (int i = k; i < n; i++){
        mp[v[i - k]]--;
        if (mp[v[i - k]] == 0) mp.erase(v[i - k]);
        mp[v[i]]++;
        cout << mp.size() << '\n';
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