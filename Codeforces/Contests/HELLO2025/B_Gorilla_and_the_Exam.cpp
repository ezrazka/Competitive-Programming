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

    map<int, int> mp;
    for (int i = 0; i < n; i++){
        mp[v[i]]++;
    }
    vector<int> freqs;
    for (auto [x, y] : mp){
        freqs.push_back(y);
    }
    sort(freqs.begin(), freqs.end());

    int ans = mp.size();
    for (int x : freqs){
        if (x <= k){
            k -= x;
            ans--;
        } else {
            break;
        }
    }
    ans = max(ans, 1ll);

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