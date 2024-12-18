#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE1 = 31;
const int BASE2 = 37;
const int INV1 = 129032259;
const int INV2 = 297297300;

template<typename T>
struct FenwickTree {
    int n, MOD;
    vector<T> tree;

    FenwickTree(int n, int MOD) {
        this->n = n;
        this->MOD = MOD;
        tree.assign(n + 1, 0);
    }

    FenwickTree(const vector<T>& v, int MOD) : FenwickTree(v.size(), MOD) {
        for (int idx = 1; idx <= n; idx++) {
            tree[idx] = (tree[idx] + v[idx - 1]) % MOD;
            int r = idx + (idx & -idx);
            if (r <= n) tree[r] = (tree[r] + tree[idx]) % MOD;
        }
    }

    void add(int idx, T val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] = (tree[idx] + val + MOD) % MOD;
        }
    }

    T query(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum = (sum + tree[idx] + MOD) % MOD;
        }
        return sum;
    }

    T sum_range(int l, int r) {
        return (query(r) - query(l - 1) + MOD) % MOD;
    }

    void update(int idx, T val) {
        T old_val = query(idx) - query(idx - 1);
        add(idx, val - old_val);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<int> pow1(n + 1), pow2(n + 1);
    pow1[0] = 1, pow2[0] = 1;
    for (int i = 1; i <= n; i++){
        pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
        pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
    }
    vector<int> powinv1(n + 1), powinv2(n + 1);
    powinv1[0] = 1, powinv2[0] = 1;
    for (int i = 1; i <= n; i++){
        powinv1[i] = (powinv1[i - 1] * INV1) % MOD1;
        powinv2[i] = (powinv2[i - 1] * INV2) % MOD2;
    }
    
    vector<int> hashes_f1(n), hashes_f2(n);
    for (int i = 0; i < n; i++){
        hashes_f1[i] = ((s[i] - 'a' + 1) * pow1[n - 1 - i]) % MOD1;
        hashes_f2[i] = ((s[i] - 'a' + 1) * pow2[n - 1 - i]) % MOD2;
    }
    vector<int> hashes_b1(n), hashes_b2(n);
    for (int i = 0; i < n; i++){
        hashes_b1[i] = ((s[n - 1 - i] - 'a' + 1) * pow1[n - 1 - i]) % MOD1;
        hashes_b2[i] = ((s[n - 1 - i] - 'a' + 1) * pow2[n - 1 - i]) % MOD2;
    }

    FenwickTree f1(hashes_f1, MOD1), f2(hashes_f2, MOD2);
    FenwickTree b1(hashes_b1, MOD1), b2(hashes_b2, MOD2);
    
    auto get_hash_f = [&](int l, int r) -> pii {
        int hash1 = (f1.sum_range(l + 1, r + 1) * powinv1[n - 1 - r]) % MOD1;
        int hash2 = (f2.sum_range(l + 1, r + 1) * powinv2[n - 1 - r]) % MOD2;
        return {hash1, hash2};
    };
    auto get_hash_b = [&](int l, int r) -> pii {
        int hash1 = (b1.sum_range(l + 1, r + 1) * powinv1[n - 1 - r]) % MOD1;
        int hash2 = (b2.sum_range(l + 1, r + 1) * powinv2[n - 1 - r]) % MOD2;
        return {hash1, hash2};
    };

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx; cin >> idx; idx--;
            char c; cin >> c;
            f1.update(idx + 1, ((c - 'a' + 1) * pow1[n - 1 - idx]) % MOD1);
            f2.update(idx + 1, ((c - 'a' + 1) * pow2[n - 1 - idx]) % MOD2);
            b1.update((n - 1 - idx) + 1, ((c - 'a' + 1) * pow1[n - 1 - (n - 1 - idx)]) % MOD1);
            b2.update((n - 1 - idx) + 1, ((c - 'a' + 1) * pow2[n - 1 - (n - 1 - idx)]) % MOD2);
            s[idx] = c;
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << (get_hash_f(l, r) == get_hash_b(n - 1 - r, n - 1 - l) ? "YES\n" : "NO\n");
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