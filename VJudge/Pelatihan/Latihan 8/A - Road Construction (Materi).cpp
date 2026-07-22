#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU {
    int n;
    vector<int> parent, size;

    DSU(int length) {
        n = length;
        parent.assign(n, -1); // tidak ada komponent
        size.assign(n, 0);
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (parent[v] == v) return v;
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

signed main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
    }

    DSU dsu(n);
    for (int node = 0; node < n; node++) dsu.make_set(node);

    int comps = n, biggest = 0;
    for (auto [u, v] : a) {
        if (dsu.find_set(u) != dsu.find_set(v)) {
            dsu.union_sets(u, v);
            comps--;
        }
        biggest = max(biggest, dsu.size[dsu.find_set(u)]);
        cout << comps << ' ' << biggest << '\n';
    }
}
