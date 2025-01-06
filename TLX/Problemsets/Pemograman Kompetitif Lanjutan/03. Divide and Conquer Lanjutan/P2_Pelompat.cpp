#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int q; cin >> q;
    vector<vector<vector<pii>>> queries(101, vector<vector<pii>>(q));
    for (int i = 0; i < q; i++){
        int a, b, k; cin >> a >> b >> k;
        queries[k][a].push_back({b, i});
    }

    vector<int> vans(q);
    for (int i = n - 1; i >= 0; i--){
        for (int k = 1; k <= 100; k++){
            for (auto [b, idx] : queries[k][i]){
                vans[idx] += 
            }
        }    
    }

    // need a segment tree that counts:
        // the number of LNDSs in range [l + 1, r] of size Z - 1 where smallest element >= v[l]
    // O(nk + qlogn)
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}