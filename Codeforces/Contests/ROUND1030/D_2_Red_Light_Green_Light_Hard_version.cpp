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

    vector<map<int, vector<int>>> diags(2);
    for (int i = n - 1; i >= 0; i--) diags[0][(p[i] + d[i]) % k].push_back(i);
    for (int i = 0; i < n; i++) diags[1][((p[i] - d[i]) % k + k) % k].push_back(i);
    for (auto& [x, y] : diags[0]) sort(y.begin(), y.end());
    for (auto& [x, y] : diags[1]) sort(y.begin(), y.end());

    vector<vector<int>> dp(n, vector<int>(2));
    auto rec = [&](auto self, int i, int dir){
        if (dp[i][dir] != 0) return dp[i][dir];

        dp[i][dir] = 1;
        if (dir == 0){
            int diag = (p[i] + d[i]) % k;
            if (diags[0].find(diag) != diags[0].end()){
                int pos = lower_bound(diags[0][diag].begin(), diags[0][diag].end(), i) - diags[0][diag].begin() - 1;
                if (pos != -1){
                    int next_i = diags[0][diag][pos];
                    int next_dir = !dir;
                    int next = self(self, next_i, next_dir);
                    if (next == 1) return dp[i][dir];
                }
            }
        } else {
            int diag = ((p[i] - d[i]) % k + k) % k;
            if (diags[1].find(diag) != diags[1].end()){
                int pos = upper_bound(diags[1][diag].begin(), diags[1][diag].end(), i) - diags[1][diag].begin();
                if (pos != diags[1][diag].size()){
                    int next_i = diags[1][diag][pos];
                    int next_dir = !dir;
                    int next = self(self, next_i, next_dir);
                    if (next == 1) return dp[i][dir];
                }
            }
        }

        return dp[i][dir] = 2;
    };

    int q; cin >> q;
    while (q--){
        int a; cin >> a;
        if (a > p[n - 1]){
            cout << "YES\n";
            continue;
        }

        int i = lower_bound(p.begin(), p.end(), a) - p.begin();
        int j = (p[i] - a) % k;
        int dir = 1;

        int diag = ((p[i] - j) % k + k) % k;
        if (diags[1].find(diag) == diags[1].end()){
            cout << "YES\n";
            continue;
        }
        int pos = lower_bound(diags[1][diag].begin(), diags[1][diag].end(), i) - diags[1][diag].begin();
        if (pos == diags[1][diag].size()){
            cout << "YES\n";
            continue;
        }
        int next_i = diags[1][diag][pos];
        int next_dir = !dir;

        cout << (rec(rec, next_i, next_dir) == 2 ? "YES\n" : "NO\n");
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