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

    segment_tree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int pos, int low, int high, int idx, T val) {
        if (low == high) {
            tree[pos] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid) {
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high) {
        if (high < q_low || q_high < low) {
            return 0;
        }
        if (q_low <= low && high <= q_high) {
            return tree[pos];
        }

        int mid = (low + high) / 2;
        return max(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    {
        auto v = a;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        }
    }

    segment_tree<int> low(n), high(n);
    vector<int> dp_low(n), dp_high(n);
    for (int i = 0; i < n; i++) {
        low.update(a[i], high.query(a[i] + 1, n - 1) + 1);
        dp_low[i] = low.query(a[i], a[i]);
        high.update(a[i], low.query(0, a[i] - 1) + 1);
        dp_high[i] = high.query(a[i], a[i]);
    }

    int ans = max(low.query(0, n - 1), high.query(0, n - 1));
    vector<int> vans;
    {
        bool is_low = (low.query(0, n - 1) == ans);
        int target = ans;
        int prev = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (is_low) {
                if (dp_low[i] == target && (prev == -1 || a[i] < a[prev])) {
                    vans.push_back(i);
                    is_low = !is_low;
                    target--;
                    prev = i;
                }
            } else {
                if (dp_high[i] == target && (prev == -1 || a[i] > a[prev])) {
                    vans.push_back(i);
                    is_low = !is_low;
                    target--;
                    prev = i;
                }
            }
        }
    }
    reverse(vans.begin(), vans.end());

    if (ans < 3) {
        cout << 0 << '\n';
        return;
    }

    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << vans[i] << " \n"[i == ans - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
