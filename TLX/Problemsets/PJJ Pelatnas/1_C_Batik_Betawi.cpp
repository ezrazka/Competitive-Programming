#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct node {
    int u = 1e9;
    int d = -1;
    int l = 1e9;
    int r = -1;

    node(){}

    node(bool lazy){
        int u = -1;
        int d = -1;
        int l = -1;
        int r = -1;
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
        res.u = min(a.u, b.u);
        res.d = max(a.d, b.d);
        res.l = min(a.l, b.l);
        res.r = max(a.r, b.r);
        return res;
    }

    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void update(int pos, int low, int high, int idx, int r, int c){
        if (low == idx && high == idx){
            tree[pos].u = r;
            tree[pos].d = r;
            tree[pos].l = c;
            tree[pos].r = c;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid){
            update(2 * pos + 1, low, mid, idx, r, c);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, r, c);
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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    segment_tree<node> tree(n * m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            tree.update(0, 0, n * m - 1, v[i][j], i, j);
        }
    }

    int offset = 0;
    int q; cin >> q;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            r1--, c1--, r2--, c2--;
            swap(v[r1][c1], v[r2][c2]);
            tree.update(0, 0, n * m - 1, v[r1][c1], r1, c1);
            tree.update(0, 0, n * m - 1, v[r2][c2], r2, c2);
        } else if (qq == 2){
            int w; cin >> w;
            offset -= w;
            offset += n * m;
            offset %= n * m;
        } else {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            r1--, c1--, r2--, c2--;

            int l = offset, r = n * m - 1, res = -1;
            while (l <= r){
                int mid = (l + r) / 2;

                node val = tree.query(0, 0, n * m - 1, offset, mid);

                if (r1 <= val.u && val.d <= r2 && c1 <= val.l && val.r <= c2){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                    res = mid;
                }
            }

            if (res == -1){
                int l = 0, r = offset - 1;
                while (l <= r){
                    int mid = (l + r) / 2;

                    node val = tree.query(0, 0, n * m - 1, 0, mid);

                    if (r1 <= val.u && val.d <= r2 && c1 <= val.l && val.r <= c2){
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                        res = mid;
                    }
                }
            }
            
            if (res == -1){
                cout << -1 << '\n';
            } else {
                cout << (res - offset + n * m) % (n * m) << '\n';
            }
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