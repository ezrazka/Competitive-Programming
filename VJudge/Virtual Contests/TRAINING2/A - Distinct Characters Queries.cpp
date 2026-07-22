#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

class SegmentTree {
private:
    int n;
    vector<bitset<26>> tree;

    void build(int pos, int l, int r, string s) {
        if (l == r) {
            tree[pos].set(s[l] - 'a');
            return;
        }
        
        int mid = (l + r) / 2;
        build(2 * pos + 1, l, mid, s);
        build(2 * pos + 2, mid + 1, r, s);
        tree[pos] = tree[2 * pos + 1] | tree[2 * pos + 2];
    }

    void update(int pos, int l, int r, int idx, char val) {
        if (l == r) {
            tree[pos].reset();
            tree[pos].set(val - 'a');
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(2 * pos + 1, l, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, r, idx, val);
        }
        tree[pos] = tree[2 * pos + 1] | tree[2 * pos + 2];
    }

    bitset<26> query(int pos, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) {
            return bitset<26>{};
        }
        if (ql <= l && r <= qr) {
            return tree[pos];
        }

        int mid = (l + r) / 2;
        return query(2 * pos + 1, l, mid, ql, qr) | query(2 * pos + 2, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(int n) : n(n), tree(4 * n, bitset<26>{}) {}

    void build(string s) {
        build(0, 0, n - 1, s);
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    bitset<26> query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

void solve() {
    string s; cin >> s;
    int n = s.length();
    int q; cin >> q;


    SegmentTree tree(n);
    tree.build(s);

    while (q--) {
        int qq; cin >> qq;
        if (qq == 1) {
            int idx; char val; cin >> idx >> val; idx--;
            tree.update(idx, val);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << tree.query(l, r).count() << '\n';
        }
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
