#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll sum, poly_sum;
    int length;
};

node merge(const node &a, const node &b){
    return {
        a.sum + b.sum,
        a.poly_sum + b.poly_sum + b.sum * a.length,
        a.length + b.length
    };
}

constexpr int N = (1 << 19);
constexpr int M = 2e7;

int a[N];
int tree_idx[2 * N - 1];
node tree[M + 1];
int ptr = 0;

void init(int n){
    for (int pos = 2 * n - 2; pos >= 0; pos--){
        tree_idx[pos] = ptr;
        ptr += (n >> __lg(pos + 1));
        if (pos >= n - 1) tree[tree_idx[pos] + 0] = {a[pos - (n - 1)], a[pos - (n - 1)], 1};
        else {
            int k2 = __lg(n) - __lg(pos + 1) - 1;
            for (int x2 = 0; x2 < (1 << k2); x2++){
                tree[tree_idx[pos] + x2] = merge(tree[tree_idx[2 * pos + 1] + x2], tree[tree_idx[2 * pos + 2] + x2]);
                tree[tree_idx[pos] + (x2 | (1 << k2))] = merge(tree[tree_idx[2 * pos + 2] + x2], tree[tree_idx[2 * pos + 1] + x2]);
            }
        }
    }
};

node query(int pos, int low, int high, int q_low, int q_high, int x){
    if (high < q_low || q_high < low){
        return {0, 0, 0};
    }
    if (q_low <= low && high <= q_high){
        return tree[tree_idx[pos] + x];
    }

    int k = __lg(high - low + 1);
    int mid = (low + high) >> 1;
    if (!(x & (1 << (k - 1)))){
        int sz2 = (1 << (k - 1));
        return merge(
            query(2 * pos + 1, low, mid, q_low, q_high, x & (sz2 - 1)),
            query(2 * pos + 2, mid + 1, high, q_low, q_high, x & (sz2 - 1))
        );
    } else {
        int sz2 = (1 << (k - 1));
        return merge(
            query(2 * pos + 2, mid + 1, high, q_low + sz2, q_high + sz2, x & (sz2 - 1)),
            query(2 * pos + 1, low, mid, q_low - sz2, q_high - sz2, x & (sz2 - 1))
        );
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    init(n);

    int cur_x = 0;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int x; cin >> x;
            cur_x ^= x;
        } else if (qq == 2){
            int l, r; cin >> l >> r;
            cout << query(0, 0, n - 1, l, r, cur_x).sum << '\n';
        } else {
            int l, r; cin >> l >> r;
            cout << query(0, 0, n - 1, l, r, cur_x).poly_sum << '\n';
        }
    }
}