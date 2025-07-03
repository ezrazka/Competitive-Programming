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

    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        mp[v[i]]++;
    }
    set<int> left(v.begin(), v.end()), right;
    for (int i = n - 1; i >= 0; i--){
        right.insert(v[i]);
        mp[v[i]]--;
        if (mp[v[i]] == 0) left.erase(v[i]), right.erase(v[i]);
        if (left.size() == right.size()){
            right.clear();
            ans++;
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