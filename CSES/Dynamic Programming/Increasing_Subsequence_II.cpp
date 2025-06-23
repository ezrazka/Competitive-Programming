#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;
    vector<T> lazy;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = (tree[2 * pos + 1] + tree[2 * pos + 2]) % MOD;
    }

    void propagate(int pos, int low, int high){
        if (lazy[pos] != 0){
            tree[pos] += (((high - low + 1) % MOD) * (lazy[pos] % MOD)) % MOD;
            tree[pos] %= MOD;
            if (low != high){
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 1] %= MOD;
                lazy[2 * pos + 2] += lazy[pos];
                lazy[2 * pos + 2] %= MOD;
            }
            lazy[pos] = 0;
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, T val){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            lazy[pos] += val;
            lazy[pos] %= MOD;
            propagate(pos, low, high);
            return;
        }
        if (high < q_low || q_high < low){
            return;
        }

        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, q_low, q_high, val);
        update(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = (tree[2 * pos + 1] + tree[2 * pos + 2]) % MOD;
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 0;
        }

        int mid = (low + high) / 2;
        return (query(2 * pos + 1, low, mid, q_low, q_high) + query(2 * pos + 2, mid + 1, high, q_low, q_high)) % MOD;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> vals = v;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < n; i++){
        v[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    }

    segment_tree<int> st(n);
    for (int i = 0; i < n; i++){
        st.update(0, 0, n - 1, v[i], v[i], st.query(0, 0, n - 1, 0, v[i] - 1) + 1);
    }

    cout << st.query(0, 0, n - 1, 0, n - 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}