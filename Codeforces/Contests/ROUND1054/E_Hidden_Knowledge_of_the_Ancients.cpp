#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int calc(vector<int> v, int n, int k, int l, int r){
    int res = 0;
    map<int, int> mp;
    for (int i = 0, j = 0; i < n; i++){
        while (j < n && mp.size() + !mp.count(v[j]) <= k){
            mp[v[j]]++;
            j++;
        }
        res += max(0ll, min(r, j - i) - l + 1);
        mp[v[i]]--;
        if (mp[v[i]] == 0) mp.erase(v[i]);
    }
    return res;
}

void solve(){
    int n, k, l, r; cin >> n >> k >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << calc(v, n, k, l, r) - calc(v, n, k - 1, l, r) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}