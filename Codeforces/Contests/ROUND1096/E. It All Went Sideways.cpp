#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;
    vector<T> lazy;

    segment_tree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void build(int pos, int low, int high) {
        if (low == high) {
            tree[pos] = -1;
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid);
        build(2 * pos + 2, mid + 1, high);
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    void propagate(int pos, int low, int high) {
        if (lazy[pos] != -1) {
            tree[pos] = lazy[pos];
            if (low != high) {
                lazy[2 * pos + 1] = lazy[pos];
                lazy[2 * pos + 2] = lazy[pos];
            }
            lazy[pos] = -1;
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, T val) {
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high) {
            lazy[pos] = val;
            propagate(pos, low, high);
            return;
        }
        if (high < q_low || q_high < low) {
            return;
        }

        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, q_low, q_high, val);
        update(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    T query(int pos, int low, int high, int q_low, int q_high) {
        propagate(pos, low, high);
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

    segment_tree<int> st(n + 1);
    st.build(0, 0, n);

    int base = 0;
    for (int i = n - 1, mn = n + 1; i >= 0; i--) {
        base += max(0ll, a[i] - mn);
        mn = min(mn, a[i]);
    }

    int ans = base;
    for (int i = 0; i < n; i++) {
        int q = st.query(0, 0, n, a[i], a[i]);
        int move = i - q - 1;
        ans = max(ans, base + move);
        st.update(0, 0, n, a[i] + 1, n, i);
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
