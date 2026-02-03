#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;

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
    int n, b, k, x; cin >> n >> b >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> mat(x, vector<int>(x));
    for (int i = 0; i < x; i++){
        for (int d : a){
            mat[(i * 10 + d) % x][i]++;
        }
    }

    vector<vector<int>> base(x, vector<int>(1));
    base[0][0] = 1;

    vector<vector<int>> res = mat_mult(mat_exp(mat, b), base);
    
    cout << res[k][0] << '\n';

    /*
    == Simplify ==
        Given integers between [1, 9],
        How many b digit numbers num are there such that num % x = k
        where:
        * 1 <= b <= 1e9
        * 2 <= x <= 100
        * 0 <= k < x
    
    == Let's assume b is small, and try DP ==

    find all old_j such that (old_j + d * 1eI) % x = j...
    sum of all old_j where (old_j * 10 + d) % x == j
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