#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int A = 1e5;
vector<vector<int>> factors(A + 1);

void init(){
    for (int i = 1; i <= A; i++){
        for (int j = i; j <= A; j += i){
            factors[j].push_back(i);
        }
    }
}


void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int mx = *max_element(v.begin(), v.end());
    
    vector<int> dp(mx + 1);
    vector<int> freq(mx + 1);
    for (int i = 0; i < n; i++){
        for (int factor : factors[v[i]]){
            dp[factor] += freq[factor] * ((n - 1) - i);
            freq[factor]++;
        }
    }

    int ans = 0;
    for (int i = mx; i >= 1; i--){
        for (int j = 2 * i; j <= mx; j += i){
            dp[i] -= dp[j];
        }
        ans += i * dp[i];
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}