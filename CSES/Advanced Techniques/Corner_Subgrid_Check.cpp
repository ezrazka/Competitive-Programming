#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int N = 3000;

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    vector<bool> ok(k);
    vector<vector<bitset<N>>> bits(k, vector<bitset<N>>(n)); // O(k * n^2)
    for (int i = 0; i < n; i++){
        vector<bitset<N>> cur_bits(k); // O(k * n^2)
        for (int j = 0; j < n; j++){
            if (ok[v[i][j] - 'A']) continue;
            if ((cur_bits[v[i][j] - 'A'] & bits[v[i][j] - 'A'][j]).count() >= 1){ // O(n^3 / w)
                ok[v[i][j] - 'A'] = true;
                continue;
            }
            cur_bits[v[i][j] - 'A'] |= bits[v[i][j] - 'A'][j];
        }
        for (int j = 0; j < n; j++){
            bits[v[i][j] - 'A'][j][i] = 1;
        }
    }

    for (int i = 0; i < k; i++){
        cout << (ok[i] ? "YES\n" : "NO\n");
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}