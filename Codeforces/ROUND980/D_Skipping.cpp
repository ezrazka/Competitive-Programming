#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree, lazy;

    segment_tree(int new_n): n(new_n), tree(4 * n, 0), lazy(4 * n, 1e18) {}

    segment_tree(const vector<T>& v): n(v.size()), tree(4 * n, 0), lazy(4 * n, 1e18) {
        build(v);
    }

    void propagate(int pos, int low, int high) {
        if (lazy[pos] != 1e18) {
            tree[pos] = min(tree[pos], lazy[pos]);
            if (low != high) {
                lazy[2 * pos + 1] = min(lazy[2 * pos + 1], lazy[pos]);
                lazy[2 * pos + 2] = min(lazy[2 * pos + 2], lazy[pos]);
            }
            lazy[pos] = 1e18;
        }
    }

    void build(const vector<T>& v, int low, int high, int pos) {
        if (low == high) {
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(v, low, mid, 2 * pos + 1);
        build(v, mid + 1, high, 2 * pos + 2);
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void build(const vector<T>& v) {
        build(v, 0, n - 1, 0);
    }

    void update(int pos, int low, int high, int qLow, int qHigh, T newValue) {
        propagate(pos, low, high);
        if (qLow <= low && qHigh >= high) {
            lazy[pos] = min(lazy[pos], newValue);
            propagate(pos, low, high);
            return;
        }
        if (qLow > high || qHigh < low) {
            return;
        }

        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, qLow, qHigh, newValue);
        update(2 * pos + 2, mid + 1, high, qLow, qHigh, newValue);
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void update(int qLow, int qHigh, T newValue) {
        update(0, 0, n - 1, qLow, qHigh, newValue);
    }

    T query(int pos, int low, int high, int qLow, int qHigh) {
        propagate(pos, low, high);
        if (qLow <= low && qHigh >= high) {
            return tree[pos];
        }
        if (qLow > high || qHigh < low) {
            return 1e18;
        }

        int mid = (low + high) / 2;
        T qLeft = query(2 * pos + 1, low, mid, qLow, qHigh);
        T qRight = query(2 * pos + 2, mid + 1, high, qLow, qHigh);
        return min(qLeft, qRight);
    }

    T query(int qLow, int qHigh) {
        return query(0, 0, n - 1, qLow, qHigh);
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i], b[i]--;

        vector<int> temp(n, 1e18);
        segment_tree<int> tree(temp);
        tree.update(0, 0, 0);
        for (int i = 0; i < n; i++){
            if (b[i] > i){
                tree.update(i + 1, b[i], tree.query(i, i) + a[i]);
            }
        }

        int ans = 0;
        int pref = 0;
        for (int i = 0; i < n; i++){
            pref += a[i];
            ans = max(ans, pref - tree.query(i, i));
        }
        cout << ans << '\n';
    }
}