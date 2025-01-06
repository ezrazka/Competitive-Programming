#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct node {
    int mn;
    int pref_mn;
    int suff_mn;
    int best_mn;

    int mx;
    int pref_mx;
    int suff_mx;
    int best_mx;

    int len;
    int pref_len;
    int suff_len;
    int best_len;

    int sum;
    int pref_sum;
    int suff_sum;
    int best_sum;

    node(){
        mn = pref_mn = suff_mn = best_mn = 1e18;
        mx = pref_mx = suff_mx = best_mx = -1e18;
        len = pref_len = suff_len = best_len = 0;
        sum = pref_sum = suff_sum = best_sum = -1e18;
    }

    node(int val){
        mn = pref_mn = suff_mn = best_mn = val;
        mx = pref_mx = suff_mx = best_mx = val;
        len = pref_len = suff_len = best_len = 1;
        sum = pref_sum = suff_sum = best_sum = -1;
    }
};

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n){
        this->n = n;
        tree.resize(4 * n);
    }

    T merge(T a, T b){
        T res;

        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        res.len = a.len + b.len;
        res.sum = res.mx - res.mn - res.len;

        if (a.pref_sum > max(a.mx, b.pref_mx) - min(a.mn, b.pref_mn) - (a.len + b.pref_len)){
            res.pref_mn = a.pref_mn;
            res.pref_mx = a.pref_mx;
            res.pref_len = a.pref_len;
            res.pref_sum = a.pref_sum;
        } else {
            res.pref_mn = min(a.mn, b.pref_mn);
            res.pref_mx = max(a.mx, b.pref_mx);
            res.pref_len = a.len + b.pref_len;
            res.pref_sum = res.pref_mx - res.pref_mn - res.pref_len;
        }

        if (a.pref_mn > b.pref_mn)

        if (b.suff_sum > max(b.mx, a.suff_mx) - min(b.mn, a.suff_mn) - (b.len + a.suff_len)){
            res.suff_mn = b.suff_mn;
            res.suff_mx = b.suff_mx;
            res.suff_len = b.suff_len;
            res.suff_sum = b.suff_sum;
        } else {
            res.suff_mn = min(b.mn, a.suff_mn);
            res.suff_mx = max(b.mx, a.suff_mx);
            res.suff_len = b.len + a.suff_len;
            res.suff_sum = res.suff_mx - res.suff_mn - res.suff_len;
        }

        if (max({a.best_sum, b.best_sum, max(a.suff_mx, b.pref_mx) - min(a.suff_mn, b.pref_mn) - (a.suff_len + b.pref_len)}) == a.best_sum){
            res.best_mn = a.best_mn;
            res.best_mx = a.best_mx;
            res.best_len = a.best_len;
            res.best_sum = a.best_sum;
        } else if (max({a.best_sum, b.best_sum, max(a.suff_mx, b.pref_mx) - min(a.suff_mn, b.pref_mn) - (a.suff_len + b.pref_len)}) == b.best_sum){
            res.best_mn = b.best_mn;
            res.best_mx = b.best_mx;
            res.best_len = b.best_len;
            res.best_sum = b.best_sum;
        } else {
            res.best_mn = min(a.suff_mn, b.pref_mn);
            res.best_mx = max(a.suff_mx, b.pref_mx);
            res.best_len = a.suff_len + b.pref_len;
            res.best_sum = res.best_mx - res.best_mn - res.best_len;
        }
        if (a.len == 2 && b.len == 2){
            debug(max(a.suff_mx, b.pref_mx));
            debug(min(a.suff_mn, b.pref_mn));
            debug(a.suff_len);
            debug(b.pref_len);
        }

        return res;
    }

    void build(int pos, int low, int high, const vector<int>& v){
        if (low == high){
            if (low < v.size()){
                tree[pos] = node(v[low]);
            }
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void update(int pos, int low, int high, int idx, int val){
        if (low == high){
            tree[pos] = node(val);
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid){
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return node();
        }

        int mid = (low + high) / 2;
        return merge(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n, q; cin >> n >> q;
    int old_n = n;
    n = 1 << (64 - __builtin_clzll(old_n - 1));
    vector<int> v(old_n);
    for (int i = 0; i < old_n; i++){
        cin >> v[i];
    }

    segment_tree<node> tree(n);
    tree.build(0, 0, n - 1, v);

    cout << tree.query(0, 0, n - 1, 0, n - 1).best_sum + 1 << '\n';
    cout << tree.query(0, 0, n - 1, 0, n - 1).best_mn << ' ' << tree.query(0, 0, n - 1, 0, n - 1).best_mx << ' ' << tree.query(0, 0, n - 1, 0, n - 1).best_len << ' ' << tree.query(0, 0, n - 1, 0, n - 1).best_sum << '\n';
    while (q--){
        int idx, val; cin >> idx >> val; idx--;
        tree.update(0, 0, n - 1, idx, val);
        cout << tree.query(0, 0, n - 1, 0, n - 1).best_sum + 1 << '\n';
        cout << tree.query(0, 0, n - 1, 0, n - 1).best_mn << ' ' << tree.query(0, 0, n - 1, 0, n - 1).best_mx << ' ' << tree.query(0, 0, n - 1, 0, n - 1).best_len << ' ' << tree.query(0, 0, n - 1, 0, n - 1).best_sum << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}