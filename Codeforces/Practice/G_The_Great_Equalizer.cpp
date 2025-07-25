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

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    void update(int pos, int low, int high, int idx, T val){
        if (low == high){
            tree[pos] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid){
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    T query(int pos, int low, int high, int q_low, int q_high){
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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        freq[v[i]]++;
    }

    vector<int> unq = v;
    sort(unq.begin(), unq.end());
    unq.erase(unique(unq.begin(), unq.end()), unq.end());
    int m = unq.size();

    set<pair<int, int>> vals, diffs;
    for (int i = 0; i < m; i++){
        vals.insert({unq[i], 2 * i});
    }
    for (int i = 0; i < m - 1; i++){
        diffs.insert({unq[i + 1] - unq[i], 2 * i});
    }

    segment_tree<int> tree(2 * (m - 1));
    for (int i = 0; i < m - 1; i++){
        tree.update(0, 0, 2 * (m - 1) - 1, 2 * i, unq[i + 1] - unq[i]);
    }

    int q; cin >> q;
    while (q--){
        int idx, val; cin >> idx >> val; idx--;
        bool remove = (freq[v[idx]] == 1);
        bool insert = (freq.find(val) == freq.end());
        if (remove){
            int to_remove = v[idx];
        }
        if (insert){

        }
        auto [best_val, best_idx] = *diffs.rbegin();
        cout << best_val + tree.query(0, 0, 2 * (m - 1) - 1, best_idx, 2 * (m - 1) - 1) << " \n"[q == 0];
        if (remove){

        }
        if (insert){

        }
    }
    /*
    use a set to find the any index X of the max difference
    use a coordinate compressed segment tree to sum query the differences >= X

    for every query,
    there may be a removal and/or an insertion

    the set can handle this normally
    for the segment tree:
    * in the segment tree we add a gap between each difference, in case of an insertion
    * otherwise we simply set the difference value to zero, in case of a removal
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}