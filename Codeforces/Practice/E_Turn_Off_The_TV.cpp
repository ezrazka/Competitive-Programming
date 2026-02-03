#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

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

    void propagate(int pos, int low, int high){
        if (lazy[pos] != 0){
            tree[pos] += lazy[pos];
            if (low != high){
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, T val){
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
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return INF;
        }

        int mid = (low + high) / 2;
        return min(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }

    {
        vector<int> values;
        for (int i = 0; i < n; i++){
            values.push_back(l[i] - 1);
            values.push_back(l[i]);
            values.push_back(r[i]);
            values.push_back(r[i] + 1);
        }
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        for (int i = 0; i < n; i++){
            l[i] = lower_bound(values.begin(), values.end(), l[i]) - values.begin();
            r[i] = lower_bound(values.begin(), values.end(), r[i]) - values.begin();;
        }
    }

    segment_tree<int> tree(4 * n);
    for (int i = 0; i < n; i++){
        tree.update(0, 0, 4 * n - 1, l[i], r[i], 1);
    }

    int ans = -1;
    for (int i = 0; i < n; i++){
        if (tree.query(0, 0, 4 * n - 1, l[i], r[i]) > 1){
            ans = i;
            break;
        }
    }
    cout << (ans == -1 ? -1 : ans + 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}