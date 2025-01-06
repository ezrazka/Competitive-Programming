#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<int, char>> v(q);
    for (int i = 0; i < q; i++){
        cin >> v[i].fi >> v[i].se; v[i].fi--;
    }

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            int cur_dist = 1;
            dist[i][j] = max(dist[i][j], cur_dist);
            for (int k = 0; k < q; k++){
                if (v[k].fi == i && v[k].se == '+') cur_dist++;
                if (v[k].fi == j && v[k].se == '-') cur_dist--;
                dist[i][j] = max(dist[i][j], cur_dist);
            }
        }
    }
    vector<int> extra(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < q; j++){
            if (v[j].fi == i && v[j].se == '+') extra[i]++;
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, 1e18)); // dp[last][visited]
    for (int i = 0; i < n; i++) dp[i][(1 << i)] = 1;
    for (int mask = 1; mask < (1 << n); mask++){
        if (__builtin_popcount(mask) == 1) continue;
        for (int i = 0; i < n; i++){
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++){
                if (i == j || !(mask & (1 << j))) continue;
                dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + dist[j][i]);
            }
        }
    }

    int ans = 1e18;
    for (int i = 0; i < n; i++){
        ans = min(ans, dp[i][(1 << n) - 1] + extra[i]);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}