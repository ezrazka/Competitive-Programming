#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    map<int, int> mp;
    for (int i = 0; i < 4; i++){
        int x; cin >> x;
        mp[x]++;
    }

    vector<int> v;
    for (auto [x, y] : mp){
        v.push_back(y);
    }
    sort(v.rbegin(), v.rend());

    if (v[0] == 3 || v.size() > 1 && v[0] == 2 && v[1] == 2){
        cout << "Yes\n";
    } else {
        cout << "No\n";
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