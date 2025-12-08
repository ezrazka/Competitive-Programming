#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int m; cin >> m;

    bool dp[m + 1][11][11]; // dp[index][previous][difference]
    pair<int, int> prev[m + 1][11][11];
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= 10; j++){
            for (int k = 0; k <= 10; k++){
                prev[i][j][k] = {-1, -1};
            }
        }
    }
    memset(dp, false, sizeof(dp));
    for (int d = 1; d <= 10; d++){
        if (!(s[d - 1] - '0')) continue;
        dp[1][d][d] = true;
    }
    for (int i = 2; i <= m; i++){
        for (int d = 1; d <= 10; d++){
            if (!(s[d - 1] - '0')) continue;
            for (int prev_d = 1; prev_d <= 10; prev_d++){
                if (!(s[prev_d - 1] - '0')) continue;
                if (d == prev_d) continue;
                for (int diff = 1; diff < d; diff++){
                    if (dp[i - 1][prev_d][d - diff]){
                        dp[i][d][diff] = true;
                        prev[i][d][diff] = {prev_d, d - diff};
                    }
                }
            }
        }
    }

    int d = -1, diff = -1;
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j <= 10; j++){
            if (dp[m][i][j]){
                d = i, diff = j;
                i = 10, j = 10;
            }
        }
    }

    if (d == -1){
        cout << "NO\n";
        return;
    }

    vector<int> vans;
    int i = m;
    while (i > 0){
        vans.push_back(d);
        auto [new_d, new_diff] = prev[i][d][diff];
        d = new_d, diff = new_diff;
        i--;
    }
    reverse(vans.begin(), vans.end());

    cout << "YES\n";
    for (int i = 0; i < m; i++){
        cout << vans[i] << " \n"[i == m - 1];
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