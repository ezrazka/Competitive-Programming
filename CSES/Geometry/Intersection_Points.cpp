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
            tree[pos] += val;
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
    int mx = 2e6 + 1;
    vector<vector<int>> adds(mx), removes(mx);
    vector<vector<pair<int, int>>> queries(mx);
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6, y1 += 1e6, x2 += 1e6, y2 += 1e6;
        if (x1 == x2){
            queries[x1].push_back({y1, y2});
        } else {
            adds[x1].push_back(y1);
            removes[x2].push_back(y1);
        }
    }

    segment_tree<int> tree(mx);

    int ans = 0;
    for (int i = 0; i < mx; i++){
        for (int idx : removes[i]){
            tree.update(0, 0, mx - 1, idx, -1);
        }
        for (auto [l, r] : queries[i]){
            ans += tree.query(0, 0, mx - 1, l + 1, r - 1);
        }
        for (int idx : adds[i]){
            tree.update(0, 0, mx - 1, idx, 1);
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}