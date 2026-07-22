#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    
    int m = __lg((int) 1e9) + 1;
    int sparse_table[n][m];
    memset(sparse_table, -1, sizeof(sparse_table));
    for (int u = 0; u < n; u++) {
        int v; cin >> v; v--;
        sparse_table[u][0] = v;
    }
 
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (sparse_table[i][j - 1] == -1) break;
            sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
        }
    }
 
    while (q--) {
        int i, k; cin >> i >> k; i--;
 
        for (int bit = 0; bit < m; bit++) {
            if (k & (1 << bit)) {
                i = sparse_table[i][bit];
            }
            if (i == -1) break;
        }
        cout << (i == - 1 ? - 1 : i + 1) << '\n';
    }
}
