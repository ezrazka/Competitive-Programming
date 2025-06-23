#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1])});
        }
    }

    vector<int> vans;
    int i = n, j = m;
    while (i >= 1 && j >= 1){
        if (a[i - 1] == b[j - 1]){
            vans.push_back(a[i - 1]);
            i--, j--;
        } else if (dp[i - 1][j] == dp[i][j]){
            i--;
        } else {
            j--;
        }
    }
    reverse(vans.begin(), vans.end());

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
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