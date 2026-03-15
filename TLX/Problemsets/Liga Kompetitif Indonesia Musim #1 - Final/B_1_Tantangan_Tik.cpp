#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int r, c, n; cin >> r >> c >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int m = r + c;

    auto parity = [&](int a){
        a--;
        return ((a / c) ^ (a % c)) & 1;
    };

    auto dist = [&](int a, int b){
        a--, b--;
        return abs(a / c - b / c) + abs(a % c - b % c);
    };

    vector<int> dp(n + 1);
    {
        vector<vector<int>> prev_dp(2);
        vector<int> prev_mx(2);
        {
            dp[1] = 1;
            int p = parity(a[1]) ^ 1;
            prev_dp[p].push_back(1);
        }
        for (int i = 2; i <= n; i++){
            int p = parity(a[i]) ^ (i & 1);
            dp[i] = prev_mx[p] + 1;
            for (int idx = (int) prev_dp[p].size() - 1; idx >= max(0ll, (int) prev_dp[p].size() - m); idx--){
                int j = prev_dp[p][idx];
                if (i - j >= dist(a[j], a[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            prev_dp[p].push_back(i);
            if (prev_dp[p].size() >= m){
                prev_mx[p] = max(prev_mx[p], dp[prev_dp[p][prev_dp[p].size() - m]]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}