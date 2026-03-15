#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int l, n, m; cin >> l >> n >> m;
    vector<int> a(l + 1);
    for (int i = 1; i <= l; i++){
        cin >> a[i];
    }
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> b[i][j];
        }
    }

    { // make a[i] all unique
        vector<bool> found(n * m + 1);
        for (int i = 1; i <= l; i++){
            if (found[a[i]]){
                while (a.size() - 1 >= i){
                    a.pop_back();
                }
                break;
            }
            found[a[i]] = true;
        }
        l = a.size() - 1;
    }
    
    vector<int> ks(n * m + 1, -1);
    for (int i = 1; i <= l; i++){
        ks[a[i]] = i;
    }

    bool dp[n + 1][m + 1];
    memset(dp, true, sizeof(dp));
    {
        int max_j[l + 1], max_j_false[l + 1];
        memset(max_j, -1, sizeof(max_j));
        memset(max_j_false, -1, sizeof(max_j_false));
        for (int i = n; i >= 1; i--){
            for (int j = m; j >= 1; j--){
                int k = ks[b[i][j]];
                if (k == -1) continue;
                if (max_j[k] >= j) continue;
                
                if (k == l) dp[i][j] = false;
                else dp[i][j] = (max_j_false[k + 1] > j);
                
                max_j[k] = max(max_j[k], j);
            }
            for (int j = m; j >= 1; j--){
                int k = ks[b[i][j]];
                if (k == -1) continue;

                if (!dp[i][j]) max_j_false[k] = max(max_j_false[k], j);
            }
        }
    }
    
    bool ok = false;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int k = ks[b[i][j]];
            if (k != 1) continue;
            if (!dp[i][j]){
                ok = true;
                i = n + 1, j = m + 1;
            }
        }
    }
    cout << (ok ? "T\n" : "N\n");
    /*
    Two observations:
    * If we already calculated the same value at dp[i..n][j..m] we can skip it
        (greedily reduce opponents options)
    * Through skipping these, we guarantee we only need to check for the first occurence of a[l]
        (each value is guaranteed to have a fixed k)
    Time Complexity: O(n * m + l)
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