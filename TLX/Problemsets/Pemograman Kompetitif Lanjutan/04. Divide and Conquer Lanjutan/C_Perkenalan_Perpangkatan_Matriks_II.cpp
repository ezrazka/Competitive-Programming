#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

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
    int n; cin >> n;

    vector<vector<int>> mat = {
        {1, 1},
        {1, 0},
    };

    vector<vector<int>> base = {
        {1},
        {1},
        {1}
    };

    vector<vector<int>> res = mat_mult(mat_exp(mat, n), base);

    cout << res[0][0] << '\n';
    /*
    dp[i][1, 2, 3] = dp[i - 3][1, 2] + dp[i - 2][1] + dp[i - 1][0]
    dp[i - 3][1, 2] = dp[i - 3]
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