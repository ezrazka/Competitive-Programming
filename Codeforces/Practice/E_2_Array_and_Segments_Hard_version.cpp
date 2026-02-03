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
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return -INF;
        }

        int mid = (low + high) / 2;
        return max(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<array<int, 3>>> upds(n);
    vector<pair<int, int>> segs(m);
    for (int i = 0; i < m; i++){
        int l, r; cin >> l >> r; l--, r--;
        upds[l].push_back({l, r, -1});
        if (r + 1 < n){
            upds[r + 1].push_back({l, r, 1});
        }
        segs[i] = {l, r};
    }

    segment_tree<int> tree(n);
    tree.build(0, 0, n - 1, a);

    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++){
        for (auto [l, r, val] : upds[i]){
            tree.update(0, 0, n - 1, l, r, val);
        }
        int mx = tree.query(0, 0, n - 1, 0, n - 1);
        int mn = tree.query(0, 0, n - 1, i, i);
        ans = max(ans, {mx - mn, i});
    }

    vector<int> vans;
    for (int i = 0; i < m; i++){
        auto [l, r] = segs[i];
        if (l <= ans.second && ans.second <= r){
            vans.push_back(i);
        }
    }

    cout << ans.first << '\n';
    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] + 1 << " \n"[i == vans.size() - 1];
    }

    /*
    Observations:
        * if we fix i to store the maximum b[i],
            its always optimal to only take all segments not including i
        * if we fix i to store the minimum b[i],
            its always optimal to take only take all segments including i
    
        is there a way to efficiently check one of these?
        can i sliding window somehow? i can use sliding window (ill do observation 2)
    
        whenever i enter index i, i add    all segments where l = i
        whenever i exit  index i, i remove all segments where r = i
        i then store these values in an (range add, range max) segment tree
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}