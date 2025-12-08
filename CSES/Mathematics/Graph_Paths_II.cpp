#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = (ll)1e18 + 1;

vector<vector<ll>> mult_blocked(const vector<vector<ll>>& a,
                                const vector<vector<ll>>& b) {
    int n = a.size();
    int m = b[0].size();
    int kdim = a[0].size();

    const int B = 64;

    vector<vector<ll>> res(n, vector<ll>(m, INF));

    for (int ii = 0; ii < n; ii += B) {
        int i_end = min(ii + B, n);

        for (int kk = 0; kk < kdim; kk += B) {
            int k_end = min(kk + B, kdim);

            for (int jj = 0; jj < m; jj += B) {
                int j_end = min(jj + B, m);

                for (int i = ii; i < i_end; i++) {
                    const auto &ai = a[i];
                    auto &ri = res[i];

                    for (int k = kk; k < k_end; k++) {
                        ll aik = ai[k];
                        if (aik == INF) continue;

                        const auto &bk = b[k];

                        for (int j = jj; j < j_end; j++) {
                            ll cand = aik + bk[j];
                            if (cand < ri[j]) ri[j] = cand;
                        }
                    }
                }

            }
        }
    }

    return res;
}

vector<vector<ll>> matexp(vector<vector<ll>> a, long long p) {
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) res[i][i] = 0;

    while (p > 0) {
        if (p & 1) res = mult_blocked(res, a);
        a = mult_blocked(a, a);
        p >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u][v] = min(adj[u][v], w);
    }

    ll ans = matexp(adj, k)[0][n-1];
    cout << (ans >= INF ? -1 : ans) << "\n";
}