#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int X = 1e5 + 1;
vector<bool> dp(X);

void solve(){
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> factors;
    for (int i = 1; i * i <= x; i++){
        if (x % i == 0){
            factors.push_back(i);
            if (i != x / i){
                factors.push_back(x / i);
            }
        }
    }
    sort(factors.rbegin(), factors.rend());

    dp[1] = true;

    int ans = 1;
    for (int i = 0; i < n; i++){
        for (int factor : factors){
            if (x % (factor * v[i]) == 0 && dp[factor]){
                dp[factor * v[i]] = true;
            }
        }
        if (dp[x]){
            ans++;
            for (int factor : factors){
                dp[factor] = false;
            }
            dp[1] = true;
            dp[v[i]] = true;
        }
    }
    cout << ans << '\n';

    for (int factor : factors){
        dp[factor] = false;
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