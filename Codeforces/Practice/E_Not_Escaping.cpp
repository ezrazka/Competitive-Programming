#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> x[i];
    }
    vector<vector<array<int, 5>>> ops(n + 1);
    for (int i = 1; i <= k; i++){
        int a, b, c, d, h; cin >> a >> b >> c >> d >> h;
        ops[c].push_back({0, d, a, b, h}); // come
        ops[a].push_back({1, b, c, d, h}); // go
    }

    vector<map<int, int>> dp(n + 1);
    for (int i = 1; i < n; i++){
        sort(ops[i].begin(), ops[i].end(), [&](const array<int, 5> &a, const array<int, 5> &b){
            auto [op_a, b_a, c_a, d_a, h_a] = a;
            auto [op_b, b_b, c_b, d_b, h_b] = b;
            return make_pair(b_a, op_a) < make_pair(b_b, op_b);
        });
        {
            int mn = (i == 1 ? 0 : INF);
            int last = 1;
            for (int j = 0; j < ops[i].size(); j++){
                auto [op, b, c, d, h] = ops[i][j];
                if (op == 0){
                    if (dp[i].find(b) == dp[i].end()) continue;
                    if (dp[i][b] < mn + (b - last) * x[i]){
                        mn = dp[i][b];
                        last = b;
                    }
                } else {
                    if (mn == INF) continue;
                    if (dp[c].find(d) == dp[c].end()){
                        dp[c][d] = mn + (b - last) * x[i] - h;
                    } else {
                        dp[c][d] = min(dp[c][d], mn + (b - last) * x[i] - h);
                    }
                }
            }
        }
        sort(ops[i].begin(), ops[i].end(), [&](const array<int, 5> &a, const array<int, 5> &b){
            auto [op_a, b_a, c_a, d_a, h_a] = a;
            auto [op_b, b_b, c_b, d_b, h_b] = b;
            return make_pair(b_a, -op_a) > make_pair(b_b, -op_b);
        });
        {
            int mn = INF;
            int last = n;
            for (int j = 0; j < ops[i].size(); j++){
                auto [op, b, c, d, h] = ops[i][j];
                if (op == 0){
                    if (dp[i].find(b) == dp[i].end()) continue;
                    if (dp[i][b] < mn + (last - b) * x[i]){
                        mn = dp[i][b];
                        last = b;
                    }
                } else {
                    if (mn == INF) continue;
                    if (dp[c].find(d) == dp[c].end()){
                        dp[c][d] = mn + (last - b) * x[i] - h;
                    } else {
                        dp[c][d] = min(dp[c][d], mn + (last - b) * x[i] - h);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (auto [j, cost] : dp[n]){
        ans = min(ans, cost + (m - j) * x[n]);
    }

    if (ans == INF){
        cout << "NO ESCAPE\n";
        return;
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