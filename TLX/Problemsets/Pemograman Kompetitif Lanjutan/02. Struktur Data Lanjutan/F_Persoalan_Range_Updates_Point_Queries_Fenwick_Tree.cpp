#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

template<typename T>
struct FenwickTree {
    int n;
    vector<T> BIT1, BIT2;

    FenwickTree(int n){
        this->n = n;
        BIT1.assign(n + 1, 0);
        BIT2.assign(n + 1, 0);
    }

    void add(vector<T>& BIT, int idx, T val){
        for (; idx <= n; idx += idx & -idx){
            BIT[idx] += val;
        }
    }

    void add_range(int l, int r, T val){
        add(BIT1, l, val);
        add(BIT1, r + 1, -val);
        add(BIT2, l, val * (l - 1));
        add(BIT2, r + 1, -val * r);
    }

    T prefix_sum(const vector<T>& BIT, int idx){
        T res = 0;
        for (; idx >= 1; idx -= idx & -idx){
            res += BIT[idx];
        }
        return res;
    }

    T sum(int idx){
        return idx * prefix_sum(BIT1, idx) - prefix_sum(BIT2, idx);
    }

    T sum_range(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void update(int idx, T val){
        T old_val = sum_range(idx, idx);
        add_range(idx, idx, val - old_val);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    FenwickTree<int> BIT(n);
    for (int i = 0; i < n; i++){
        BIT.update(i + 1, v[i]);
    }

    int q; cin >> q;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int l, r, val; cin >> l >> r >> val;
            BIT.add_range(l, r, val);
        } else {
            int idx; cin >> idx;
            cout << BIT.sum_range(idx, idx) << '\n';
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