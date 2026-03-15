#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

vector<vector<int>> mat_mult(const vector<vector<int>>& a, const vector<vector<int>>& b){
    vector<vector<int>> res(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            for (int k = 0; k < b[0].size(); k++){
                res[i][k] += (a[i][j] * b[j][k]) % MOD;
                res[i][k] %= MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> mat_exp(vector<vector<int>>& a, int b){
    vector<vector<int>> res(a.size(), vector<int>(a[0].size(), 0));
    for (int i = 0; i < a.size(); i++){
        res[i][i] = 1;
    }
    while (b > 0){
        if (b & 1) res = mat_mult(res, a);
        a = mat_mult(a, a);
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, m, l, r; cin >> n >> m >> l >> r;

    if (n * m & 1){
        cout << binpow(r - l + 1, n * m) << '\n';
        return;
    }

    int evens = r / 2 - (l - 1) / 2;
    int odds = (r - l + 1) - evens;

    vector<vector<int>> base = {
        {evens, odds},
        {odds, evens}
    };
    vector<vector<int>> res = {
        {1}, // dp[0][0]
        {0}  // dp[0][1]
    };
    res = mat_mult(mat_exp(base, n * m), res);
    cout << res[0][0] << '\n';
    /*
    fails when n * m is even and there are an odd number of a[i][j] & 1
    n * m is odd -> (r - l + 1)^(n * m)
    n * m is even -> solvable with dp, efficiently with matexp

    DP SOLUTION:
    ```
    vector<vector<int>> dp(n + m + 1, vector<int>(2));
    dp[0][0] = 1;
    for (int i = 1; i <= n * m; i++){
        dp[i][0] = (dp[i - 1][0] * evens + dp[i - 1][1] * odds) % MOD;
        dp[i][1] = (dp[i - 1][1] * evens + dp[i - 1][0] * odds) % MOD;
    }
    cout << dp[n * m][0] << '\n';
    ```
    
    MATEXP SOLUTION:
    ```
    vector<vector<int>> base = {
        {evens, odds},
        {odds, evens}
    };
    vector<vector<int>> res = {
        {1}, // dp[0][0]
        {0}, // dp[0][1]
    };
    res = mat_mult(mat_exp(base, n * m), res);
    cout << res[0][0] << '\n';
    ```
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