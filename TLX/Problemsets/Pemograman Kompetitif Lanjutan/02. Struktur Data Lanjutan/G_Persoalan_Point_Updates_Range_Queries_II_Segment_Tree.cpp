#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void update(int pos, int low, int high, int idx, T val){
        if (low == high){
            tree[pos] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid){
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 0;
        }

        int mid = (low + high) / 2;
        return max(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    segment_tree<int> tree(n);
    tree.build(0, 0, n - 1, v);

    int q; cin >> q;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx, val; cin >> idx >> val; idx--;
            tree.update(0, 0, n - 1, idx, val);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << tree.query(0, 0, n - 1, l, r) << '\n';
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