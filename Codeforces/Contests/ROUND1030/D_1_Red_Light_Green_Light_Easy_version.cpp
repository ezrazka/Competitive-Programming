#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> p(n); for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> d(n); for (int i = 0; i < n; i++) cin >> d[i];
    int q; cin >> q;
    vector<int> a(q); for (int i = 0; i < q; i++) cin >> a[i];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));
    auto rec = [&](auto self, int i, int j, int dir){
        if (dp[i][j][dir] != 0) return dp[i][j][dir];

        dp[i][j][dir] = 1;
        if (i - 1 >= 0 && dir == 0){
            int next_j = (j + abs(p[i] - p[i - 1])) % k;
            int next = self(self, i - 1, next_j, dir ^ (next_j == d[i - 1]));
            if (next == 1) return dp[i][j][dir];
        }
        if (i + 1 < n && dir == 1){
            int next_j = (j + abs(p[i] - p[i + 1])) % k;
            int next = self(self, i + 1, next_j, dir ^ (next_j == d[i + 1]));
            if (next == 1) return dp[i][j][dir];
        }
        return dp[i][j][dir] = 2;
    };

    for (int query : a){
        int i = lower_bound(p.begin(), p.end(), query) - p.begin();
        if (i == n){
            cout << "YES\n";
            continue;
        }
        int j = (p[i] - query) % k;
        int dir = (j != d[i]);

        cout << (rec(rec, i, j, dir) == 2 ? "YES\n" : "NO\n");
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