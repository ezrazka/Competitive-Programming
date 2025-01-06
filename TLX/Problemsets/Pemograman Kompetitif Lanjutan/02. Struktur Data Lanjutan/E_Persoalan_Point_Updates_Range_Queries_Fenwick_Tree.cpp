#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct fenwick_tree {
    int n;
    vector<int> BIT;

    fenwick_tree(int n){
        this->n = n;
        BIT.assign(n + 1, 0);
    }

    void add(int idx, int val){
        for (; idx <= n; idx += idx & -idx){
            BIT[idx] += val;
        }
    }

    int sum(int idx){
        int res = 0;
        for (; idx >= 1; idx -= idx & -idx){
            res += BIT[idx];
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    fenwick_tree BIT(n);
    for (int i = 0; i < n; i++){
        BIT.add(i + 1, v[i]);
    }

    int q; cin >> q;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx, val; cin >> idx >> val; idx--;
            BIT.add(idx + 1, val);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << BIT.sum(r + 1) - BIT.sum(l) << '\n';
        }
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