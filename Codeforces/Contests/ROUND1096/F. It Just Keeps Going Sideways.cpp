#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int pos, int low, int high, int idx, T val) {
        if (low == high) {
            tree[pos] += val;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid) {
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    T query(int pos, int low, int high, int q_low, int q_high) {
        if (q_low <= low && high <= q_high) {
            return tree[pos];
        }
        if (high < q_low || q_high < low) {
            return 0;
        }

        int mid = (low + high) / 2;
        return query(2 * pos + 1, low, mid, q_low, q_high) + query(2 * pos + 2, mid + 1, high, q_low, q_high);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segment_tree<int> cnt(n + 1);
    segment_tree<int> sum(n + 1);
    
    int base = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cur_cnt = cnt.query(0, 0, n, 1, a[i] - 1);
        int cur_sum = sum.query(0, 0, n, 1, a[i] - 1);
        base += cur_cnt * a[i] - cur_sum;
        cnt.update(0, 0, n, a[i], 1);
        sum.update(0, 0, n, a[i], a[i]);
    }

    int ans = base;
    ordered_set<int> st;
    for (int i = 0; i < n; i++) {
        int cur = st.size() - st.order_of_key(a[i]);
        ans = max(ans, base + cur);
        st.insert(a[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
