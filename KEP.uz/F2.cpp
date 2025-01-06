#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
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

    // FenwickTree(const vector<T>& v) : FenwickTree(v.size()){
    //     for (int idx = 1; idx <= n; idx++){
    //         BIT1[idx] += v[idx - 1];
    //         int r = idx + (idx & -idx);
    //         if (r <= n) BIT1[r] += BIT1[idx];
    //         BIT2[idx] += v[idx - 1] * (idx - 1);
    //         if (r <= n) BIT2[r] += BIT2[idx];
    //     }
    // }

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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    FenwickTree<int> pref(n + 1), pref2(n + 1);
    for (int i = 1; i <= n; i++){
        pref.add_range(i, i, v[i]);
        pref2.add_range(i, i, i * v[i]);
    }
    FenwickTree<int> suff(n + 1), suff2(n + 1);
    for (int i = 1; i <= n; i++){
        suff.add_range(i, i, v[n - i + 1]);
        suff2.add_range(i, i, i * v[n - i + 1]);
    }

    int q; cin >> q;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx, val; cin >> idx >> val;
            pref.update(idx, val);
            pref2.update(idx, idx * val);
            suff.update((n - idx + 1), val);
            suff2.update((n - idx + 1), (n - idx + 1) * val);
        } else {
            int k; cin >> k;
            k = min(k, n - k + 1);
            int ans = pref2.sum_range(1, k - 1) + k * (pref.sum_range(1, n - k + 1) - pref.sum_range(1, k - 1)) + suff2.sum_range(1, k - 1);
            cout << ans << '\n';
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