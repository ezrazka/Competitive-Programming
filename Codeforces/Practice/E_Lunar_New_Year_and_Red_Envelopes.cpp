#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<array<int, 3>>> ops(n + 1);
    for (int _ = 0; _ < k; _++){
        int s, t, d, w; cin >> s >> t >> d >> w;
        ops[s].push_back({t, d, w});
    }

    vector<pair<int, int>> timeline(n + 1, {-1, -1});
    {
        priority_queue<array<int, 3>> pq;
        for (int s = 1; s <= n; s++){
            for (auto [t, d, w] : ops[s]){
                pq.push({w, d, t});
            }
            while (!pq.empty() && pq.top()[2] < s) pq.pop();
            if (!pq.empty()) timeline[s] = {pq.top()[0], pq.top()[1]};
        }
    }

    vector<vector<int>> dp(n + 2, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++){
        auto [w, d] = timeline[i];
        for (int j = 0; j <= m; j++){
            if (w != -1){
                dp[d + 1][j] = min(dp[d + 1][j], dp[i][j] + w);
            } else {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
            if (j + 1 <= m){
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= m; i++){
        ans = min(ans, dp[n + 1][i]);
    }
    cout << ans << '\n';

    /*
    Observations:
        * because t[i] <= d[i], we never have to worry about double counting
        * we either cover a segment entirely or not at all
        * it's useful to thing as the segments as teleporters toward d[i] + 1
        * each index only cares about the maximum {w[i], d[i]} covering that index
        * we can offline range chmax the {w[i], d[i]}s, and we can use push dp
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