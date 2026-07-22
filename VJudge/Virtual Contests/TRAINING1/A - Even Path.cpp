#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

struct DSU {
    int n;
    vector<int> parent, size;

    DSU(int n_) {
        n = n_;
        parent.assign(n, -1);
        size.assign(n, 0);
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] &= 1;
    for (int i = 1; i <= n; i++) cin >> b[i], b[i] &= 1;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + b[i];
    }

    vector<int> comp(n + 1, -1);
    auto dfs = [&](auto self, int node, int source) -> void {
        if (node < 1 || node > n || comp[node] != -1 || a[node] != a[source]) return;
        comp[node] = source;
        self(self, node - 1, source);
        self(self, node + 1, source);
    };
    for (int node = 1; node <= n; node++) {
        if (comp[node] == -1) {
            dfs(dfs, node, node);
        }
    }

    auto connected = [&](int ra, int ca, int rb, int cb) -> bool {
        if (ca > cb) swap(ca, cb);
        int sum = pref[cb] - pref[ca - 1];
        return comp[ra] == comp[rb] && (sum == 0 || sum == (cb - ca + 1));
    };

    while (q--) {
        int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
        cout << (connected(ra, ca, rb, cb) ? "YES\n" : "NO\n");
    }

    /*
        Case 1: all same color
            Check if connected on the same column
        Case 2: theres a different color
            * use flood fill between two columns
    */
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
