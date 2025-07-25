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
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
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
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 0;
        }

        int mid = (low + high) / 2;
        return max(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> freq(n + 2);
    vector<pair<int, int>> intervals(m);
    for (int i = 0; i < m; i++){
        cin >> intervals[i].fi >> intervals[i].se;
        freq[intervals[i].fi]++;
        freq[intervals[i].se + 1]--;
    }

    set<int> st;
    int zeros = 0;
    for (int i = 1; i <= n; i++){
        freq[i] += freq[i - 1];
        if (1 <= freq[i] && freq[i] <= 2){
            st.insert(i);
        }
        if (freq[i] == 0){
            zeros++;
        }
    }

    vector<vector<int>> idxs(n + 1);
    for (int i = 0; i < m; i++){
        auto [l, r] = intervals[i];
        auto it = st.lower_bound(l);
        while (it != st.end() && *it <= r){
            idxs[*it].push_back(i);
            it++;
        }
    }

    vector<vector<pair<int, int>>> adj(m);
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++){
        if (idxs[i].size() == 2){
            int u = idxs[i][0];
            int v = idxs[i][1];
            mp[{u, v}]++;
        }
    }
    for (auto [key, val] : mp){
        auto [u, v] = key;
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
    }
    vector<int> single(m);
    for (int i = 1; i <= n; i++){
        if (idxs[i].size() == 1){
            single[idxs[i][0]]++;
        }
    }

    int ans = 0;
    segment_tree<int> tree(m);
    tree.build(0, 0, m - 1, single);
    for (int i = 0; i < m; i++){
        tree.update(0, 0, m - 1, i, -single[i]);
        for (auto [child, weight] : adj[i]){
            tree.update(0, 0, m - 1, child, weight);
        }
        ans = max(ans, zeros + single[i] + tree.query(0, 0, m - 1, 0, m - 1));
        tree.update(0, 0, m - 1, i, single[i]);
        for (auto [child, weight] : adj[i]){
            tree.update(0, 0, m - 1, child, -weight);
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}