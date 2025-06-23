#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int gcd = 0;
    for (int i = 0; i < n; i++){
        gcd = __gcd(gcd, v[i]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++){
        v[i] /= gcd;
        mx = max(mx, v[i]);
    }
    
    vector<int> dp(mx + 1, 1e9);
    for (int i = 0; i < n; i++){
        dp[v[i]] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 1; j < v[i]; j++){
            dp[__gcd(v[i], j)] = min(dp[__gcd(v[i], j)], dp[j] + 1);
        }
        dp[v[i]] = 1;
    }

    cout << (dp[1] - 1) + (n - count(v.begin(), v.end(), 1)) - !count(v.begin(), v.end(), 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}