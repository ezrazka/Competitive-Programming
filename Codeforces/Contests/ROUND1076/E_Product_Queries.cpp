#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();

    vector<int> dp(n + 1, INF);
    dp[1] = 0;
    for (int i = 1; i < n; i++){
        if (dp[i] == INF) continue;
        for (int num : a){
            if (i * num > n) break;
            dp[i * num] = min(dp[i * num], dp[i] + 1);
        }
    }
    dp[1] = (a[0] == 1 ? 1 : INF);

    for (int i = 1; i <= n; i++){
        cout << (dp[i] == INF ? -1 : dp[i]) << " \n"[i == n];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}