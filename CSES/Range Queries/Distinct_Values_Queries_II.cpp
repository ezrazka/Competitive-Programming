#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"
 
template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;
 
    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 1e9);
    }
 
    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }
 
        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
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
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
 
    T query(int pos, int low, int high, int q_low, int q_high){
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 1e9;
        }
 
        int mid = (low + high) / 2;
        return min(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};
 
void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    segment_tree<int> st(n);
    map<int, set<int>> idxs;
    vector<int> base(n, n);
    for (int i = n - 1; i >= 0; i--){
        if (!idxs[v[i]].empty()){
            base[i] = *idxs[v[i]].begin();
        }
        idxs[v[i]].insert(i);
    }
    st.build(0, 0, n - 1, base);
 
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx, val; cin >> idx >> val; idx--;
            auto it = idxs[v[idx]].find(idx);
            int left = it == idxs[v[idx]].begin() ? -1 : *prev(it);
            idxs[v[idx]].erase(idx);
            idxs[val].insert(idx);
            if (left != -1){
                it = idxs[v[left]].upper_bound(left);
                int new_idx = it == idxs[v[left]].end() ? n : *it;
                st.update(0, 0, n - 1, left, new_idx);
            }
            it = idxs[val].lower_bound(idx);
            int new_left = it == idxs[val].end() ? -1 : *--it;
            if (new_left != -1){
                st.update(0, 0, n - 1, new_left, idx);
            }
            it = idxs[val].upper_bound(idx);
            int new_right = it == idxs[val].end() ? n : *it;
            st.update(0, 0, n - 1, idx, new_right);
            v[idx] = val;
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << (st.query(0, 0, n - 1, l, r) > r ? "YES\n" : "NO\n");
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
