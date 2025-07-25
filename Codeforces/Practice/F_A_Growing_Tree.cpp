#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

template<typename T>
struct FenwickTree {
    int n;
    vector<T> BIT1, BIT2;

    FenwickTree(int n){
        this->n = n;
        BIT1.assign(n + 1, 0);
        BIT2.assign(n + 1, 0);
    }

    FenwickTree(const vector<T>& v) : FenwickTree(v.size()){
        for (int idx = 1; idx <= n; idx++){
            BIT1[idx] += v[idx - 1];
            int r = idx + (idx & -idx);
            if (r <= n) BIT1[r] += BIT1[idx];
            BIT2[idx] += v[idx - 1] * (idx - 1);
            if (r <= n) BIT2[r] += BIT2[idx];
        }
    }

    void add(vector<T>& BIT, int idx, T val){
        for (; idx <= n; idx += idx & -idx){
            BIT[idx] += val;
        }
    }

    void add_range(int l, int r, T val){
        add(BIT1, l, val);
        add(BIT1, r + 1, -val);
        add(BIT2, l, val * (l - 1));
        add(BIT2, r + 1, -val * r);
    }

    T prefix_sum(const vector<T>& BIT, int idx){
        T res = 0;
        for (; idx >= 1; idx -= idx & -idx){
            res += BIT[idx];
        }
        return res;
    }

    T sum(int idx){
        return idx * prefix_sum(BIT1, idx) - prefix_sum(BIT2, idx);
    }

    T sum_range(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void update(int idx, T val){
        T old_val = sum_range(idx, idx);
        add_range(idx, idx, val - old_val);
    }
};

void solve(){
    int q; cin >> q;
    vector<vector<int>> queries(q);
    int n = 1;
    for (int i = 0; i < q; i++){
        int qq; cin >> qq;
        if (qq == 1){
            int v; cin >> v; v--;
            queries[i] = {qq, v};
            n++;
        } else {
            int v, x; cin >> v >> x; v--;
            queries[i] = {qq, v, x};
        }
    }

    vector<vector<int>> adj(n);
    int u = 0;
    for (int i = 0; i < q; i++){
        if (queries[i][0] == 1){
            int v = queries[i][1];
            u++;
            adj[v].push_back(u);
        }
    }

    int timer = 0;
    vector<int> tin(n), tout(n);
    auto dfs_euler_tour = [&](auto self, int node) -> void {
        tin[node] = timer++;
        for (int child : adj[node]){
            self(self, child);
        }
        tout[node] = timer;
    };
    dfs_euler_tour(dfs_euler_tour, 0);

    FenwickTree<int> BIT(n);
    u = 0;
    for (int i = 0; i < q; i++){
        if (queries[i][0] == 1){
            int v = queries[i][1];
            u++;
            int val = BIT.sum_range(tin[v] + 1, tin[v] + 1);
            BIT.add_range(tin[u] + 1, tout[u], -val);
        } else {
            int v = queries[i][1];
            int x = queries[i][2];
            BIT.add_range(tin[v] + 1, tout[v], x);
        }
    }

    for (int i = 0; i < n; i++){
        cout << BIT.sum_range(tin[i] + 1, tin[i] + 1) << " \n"[i == n - 1];
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