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
    vector<T> lazy;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void propagate(int pos, int low, int high, int qq){
        if (lazy[pos] != 0){
            tree[pos] += (high - low + 1) * lazy[pos];
            if (low != high){
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, T val, int qq){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            lazy[pos] += val;
            propagate(pos, low, high);
            return;
        }
        if (high < q_low || q_high < low){
            return;
        }

        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, q_low, q_high, val);
        update(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 0;
        }

        int mid = (low + high) / 2;
        return query(2 * pos + 1, low, mid, q_low, q_high) + query(2 * pos + 2, mid + 1, high, q_low, q_high);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    segment_tree<int> tree(n);

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int l, r; cin >> l >> r; l--, r--;
        } else if (qq == 2){
            int l, r; cin >> l >> r; l--, r--;
        } else {
            int l, r; cin >> l >> r; l--, r--;
        }
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