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
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    FenwickTree<int> BIT(n);
    for (int i = 0; i < n; i++){
        BIT.add_range(i + 1, i + 1, v[i]);
    }

    multiset<pii> intervals;
    multiset<int> lengths;
    lengths.insert(0);
    pii cur = {-1, -1};
    bool found0 = false;
    for (int i = 0; i < n; i++){
        if (v[i] == 0 || v[i] == 1){
            if (v[i] == 0) found0 = true;
            if (cur.fi == -1){
                cur = {i, i};
            } else {
                cur.se = i;
            }
        } else if (cur.fi != -1){
            if (found0){
                intervals.insert(cur);
                lengths.insert(cur.se - cur.fi + 1);
            }
            found0 = false;
            cur = {-1, -1};
        }
    }
    if (found0){
        intervals.insert(cur);
        lengths.insert(cur.se - cur.fi + 1);
    }
    found0 = false;
    cur = {-1, -1};

    auto get_interval = [&](int idx) -> auto {
        auto it = intervals.upper_bound({idx, n - 1});
        if (it == intervals.begin() || intervals.empty()) return intervals.end();
        --it;
        if (it->fi <= idx && idx <= it->se){
            return it;
        } else {
            return intervals.end();
        }
    };

    auto is_valid_interval = [&](int l, int r) -> bool {
        if (l > r) return false;
        int sum = BIT.sum_range(l + 1, r + 1);
        return sum != r - l + 1;
    };

    while (q--){
        int idx, x; cin >> idx >> x; idx--;
        v[idx] += x;
        BIT.add_range(idx + 1, idx + 1, x);

        if (v[idx] == 1){
            auto it = get_interval(idx);
            if (it != intervals.end()){
                if (!is_valid_interval(it->fi, it->se)){
                    intervals.erase(it);
                }
            }
        } else {
            auto it = get_interval(idx);
            if (it != intervals.end()){
                pii a = {it->fi, idx - 1}, b = {idx + 1, it->se};
                lengths.erase(lengths.find(it->se - it->fi + 1));
                intervals.erase(it);
                if (is_valid_interval(a.fi, a.se)){
                    intervals.insert(a);
                    lengths.insert(a.se - a.fi + 1);
                }
                if (is_valid_interval(b.fi, b.se)){
                    intervals.insert(b);
                    lengths.insert(b.se - b.fi + 1);
                }
            }
        }
        cout << *lengths.rbegin() << '\n';
    }
    /*
    0. 0 0 0 0 0
    1. 1 0 0 0 0
    2. 1 0 0 0 1
    3. 1 0 0 0 2
    4. 1 1 0 0 2
    5. 1 1 0 1 2
    6. 2 1 0 1 2
    7. 2 2 0 1 2
    8. 2 2 0 1 3
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}