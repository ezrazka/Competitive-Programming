#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct node {
    int sum;
    int pref_sum;
    int suff_sum;
    int best_sum;

    node(){
        sum = 0;
        pref_sum = 0;
        suff_sum = 0;
        best_sum = 0;
    }

    node(int val){
        sum = val;
        pref_sum = max(0ll, val);
        suff_sum = max(0ll, val);
        best_sum = max(0ll, val);
    }
};

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, node());
    }

    T merge(T a, T b){
        node res;
        res.sum = a.sum + b.sum;
        res.pref_sum = max(a.pref_sum, a.sum + b.pref_sum);
        res.suff_sum = max(a.suff_sum + b.sum, b.suff_sum);
        res.best_sum = max({a.best_sum, b.best_sum, a.suff_sum + b.pref_sum});
        return res;
    }

    void build(int pos, int low, int high, const vector<int>& v){
        if (low == high){
            tree[pos] = node(v[low]);
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    segment_tree<node> st(n);
    st.build(0, 0, n - 1, v);

    while (q--){
        int l, r; cin >> l >> r; l--, r--;
        cout << st.query(0, 0, n - 1, l, r).best_sum << '\n';
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