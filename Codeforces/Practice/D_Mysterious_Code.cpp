#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

vector<int> prefix_function(string s){
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if (s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void solve(){
    string c, s, t; cin >> c >> s >> t;
    int k = c.length(), n = s.length(), m = t.length();
    
    vector<vector<int>> update_s(n, vector<int>(26));
    {
        vector<int> pi = prefix_function(s);
        for (int i = 0; i < n; i++){
            for (char ch = 'a'; ch <= 'z'; ch++){
                if (i != n - 1 && ch == s[i]){
                    update_s[i][ch - 'a'] = i + 1;
                } else {
                    int j = (i == 0 ? 0 : pi[i - 1]);
                    while (j > 0 && ch != s[j]){
                        j = pi[j - 1];
                    }
                    update_s[i][ch - 'a'] = min(n - 1, j + (ch == s[j]));
                }
            }
        }
    }
    vector<vector<int>> update_t(m, vector<int>(26));
    {
        vector<int> pi = prefix_function(t);
        for (int i = 0; i < m; i++){
            for (char ch = 'a'; ch <= 'z'; ch++){
                if (i != m - 1 && ch == t[i]){
                    update_t[i][ch - 'a'] = i + 1;
                } else {
                    int j = (i == 0 ? 0 : pi[i - 1]);
                    while (j > 0 && ch != t[j]){
                        j = pi[j - 1];
                    }
                    update_t[i][ch - 'a'] = min(m - 1, j + (ch == t[j]));
                }
            }
        }
    }

    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(m, -INF)));
    dp[0][0][0] = 0;
    for (int x = 0; x < k; x++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (dp[x][i][j] == -INF) continue;
                for (char ch = 'a'; ch <= 'z'; ch++){
                    if (c[x] == ch || c[x] == '*'){
                        int ii = update_s[i][ch - 'a'];
                        int jj = update_t[j][ch - 'a'];
                        int val = (i == n - 1 && s[i] == ch) - (j == m - 1 && t[j] == ch);
                        dp[x + 1][ii][jj] = max(dp[x + 1][ii][jj], dp[x][i][j] + val);
                    }
                }
            }
        }
    }

    int ans = -INF;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans = max(ans, dp[k][i][j]);
        }
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