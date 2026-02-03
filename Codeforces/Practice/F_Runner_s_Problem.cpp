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
    int n, m; cin >> n >> m;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++){
        int a, l, r; cin >> a >> l >> r; a--;
        mp[l].emplace_back(a, 1);
        mp[r + 1].emplace_back(a, -1);
    }
    mp[m + 1].emplace_back(0, 0);

    vector<int> counters(3);
    vector<vector<int>> mat(3, vector<int>(3)), res(3, vector<int>(1));
    res[1][0] = 1;
    int prev_j = 1;
    for (auto [j, vec] : mp){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                mat[i][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++){
            if (counters[i]) continue;
            for (int j = max(0ll, i - 1); j <= min(2ll, i + 1); j++){
                mat[i][j]++;
            }
        }
        mat = mat_exp(mat, (j - 1) - prev_j);
        res = mat_mult(mat, res);
        for (auto [i, val] : vec){
            counters[i] += val;
        }
        prev_j = j - 1;
    }
    cout << res[1][0] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}