#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<pair<int, int>> b; // {height, index}
    for (int i = 0; i < n; i++){
        if (a[i] == 0) continue;
        if (b.empty() || b.back().fi < a[i]){
            b.push_back({a[i], i});
        }
    }
    int m = b.size();

    int table[k + 1][k + 1];
    int dp[m + 1][k + 1][k + 1]; // dp[index][prefix maximum][cards used] -> maximum prefix max sum
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++){ // index
        auto [height, index] = b[i - 1];
        for (int j = 0; j <= height; j++){
            for (int l_min_j = 0; l_min_j <= k; l_min_j++){
                if (j == 0){
                    table[j][l_min_j] = 0;
                } else {
                    int x = j - 1;
                    int value = dp[i - 1][x][l_min_j] - x * (n - index);
                    table[j][l_min_j] = max(table[j - 1][l_min_j], value);
                }
            }
        }
        for (int j = 0; j <= height; j++){ // prefix maximum
            for (int l = 0; l <= k; l++){ // cards used
                // do nothing
                dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);

                // take
                if (l - j >= 0){
                    // for (int x = 0; x < j; x++){
                    //     int value = (j - x) * (n - index);
                    //     dp[i][j][l] = max(dp[i][j][l], dp[i - 1][x][l - j] + value);
                    // }
                    /*
                        notice how when (l - j) is fixed,
                        when x increases, it decreases by (n - index)

                        we can precompute:
                            maximum of dp[i - 1][x][l - j] - x * (n - index), for 0 <= x < j
                            and then add j * (n - index) to the result
                            in O(1)
                        this allows j to no longer be tied to the subequation,
                        allowing the maximum to be reused over many of the queries
                        therefore reducing the dimensions by a factor of k

                        so we need to query table[j][l - j] + j * (n - index)
                    */
                    dp[i][j][l] = max(dp[i][j][l], table[j][l - j] + j * (n - index));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++){
        for (int j = 0; j <= k; j++){
            ans = max(ans, dp[m][i][j]);
        }
    }
    cout << ans << '\n';

    /* UPSOLVING
        Observation I missed:
        the only indices that matter are in
        the lexicographically smallest (by indices) strictly increasing subsequence
        now solution is O(n + k^3) instead of O(n * k^2)
    */
    /*
    you must distribute a sum of k to N elements
    each element has a maximum value of a[i];

    maximize the sum of prefix maximums

    naive:
    dp[n][k][k] -> dp[index][prefix maximum][cards remaining]

    
    knapsack?
    store n * 360
    dp from the back, subset dp
    probably left-to-right

    
    O(n * k) per test case is not allowed due to test case constraints
    sum of k <= 1800 over all test cases ...precomputation?
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}