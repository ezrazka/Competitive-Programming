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
            BIT[idx] = ((BIT[idx] % 26) + 26) % 26;
        }
    }

    void add_range(int l, int r, T val){
        if (l > r) return;
        add(BIT1, l, val);
        add(BIT1, r + 1, -val);
        add(BIT2, l, val * (l - 1));
        add(BIT2, r + 1, -val * r);
    }

    T prefix_sum(const vector<T>& BIT, int idx){
        T res = 0;
        for (; idx >= 1; idx -= idx & -idx){
            res += BIT[idx];
            res = ((res % 26) + 26) % 26;
        }
        return res;
    }

    T sum(int idx){
        return ((idx * prefix_sum(BIT1, idx) - prefix_sum(BIT2, idx)) % 26 + 26) % 26;
    }

    T sum_range(int l, int r){
        if (l > r) return 0;
        return ((sum(r) - sum(l - 1)) % 26 + 26) % 26;
    }

    void update(int idx, T val){
        T old_val = sum_range(idx, idx);
        add_range(idx, idx, val - old_val);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    
    FenwickTree<int> BIT(n);
    for (int i = 0; i < n; i++){
        BIT.add_range(i + 1, i + 1, s[i] - 'a');
    }
    set<int> odd;
    for (int i = 0; i < n - 2; i++){
        if (s[i] == s[i + 2]){
            odd.insert(i + 1);
        }
    }
    set<int> even;
    for (int i = 0; i < n - 1; i++){
        if (s[i] == s[i + 1]){
            even.insert(i + 1);
        }
    }

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int l, r, x; cin >> l >> r >> x; x %= 26;
            vector<pair<int, int>> odd_pairs = {{l - 2, l}, {l - 1, l + 1}, {r - 1, r + 1}, {r, r + 2}};
            vector<pair<int, int>> even_pairs = {{l - 1, l}, {r, r + 1}};
            {
                for (auto [x, y] : odd_pairs){
                    if (1 <= x && y <= n && BIT.sum_range(x, x) == BIT.sum_range(y, y)){
                        odd.erase(x);
                    }
                }
                for (auto [x, y] : even_pairs){
                    if (1 <= x && y <= n && BIT.sum_range(x, x) == BIT.sum_range(y, y)){
                        even.erase(x);
                    }
                }
            }
            BIT.add_range(l, r, x);
            {
                for (auto [x, y] : odd_pairs){
                    if (1 <= x && y <= n && BIT.sum_range(x, x) == BIT.sum_range(y, y)){
                        odd.insert(x);
                    }
                }
                for (auto [x, y] : even_pairs){
                    if (1 <= x && y <= n && BIT.sum_range(x, x) == BIT.sum_range(y, y)){
                        even.insert(x);
                    }
                }
            }
        } else {
            int l, r; cin >> l >> r;
            bool ok = true;
            if (odd.lower_bound(l) != odd.end() && *odd.lower_bound(l) <= r - 2) ok = false;
            if (even.lower_bound(l) != even.end() && *even.lower_bound(l) <= r - 1) ok = false;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    /*
    the WAs were cuz i used the % 26 fenwick tree to count the freq instead of a normal fenwick tree

    * to range query OR a boolean array, we can use fenwick trees or use sets
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