#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> suff(n + 1);
    for (int i = n - 1; i >= 0; i--){
        suff[i] = suff[i + 1] + (n - i) * ((i + 1) + n);
    }

    vector<int> pref(n + 1);
    for (int i = 0, sum = 0; i < n; i++){
        suff[i] += sum;
        sum += v[i];
    }

    int ans = accumulate(v.begin(), v.end(), 0ll);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--){
        ans = max(ans, pref[i] + (suff[i]) + sum);
        sum += v[i];
    }

    // (r - l + 1) * (l + r) - (l + r) - (r - l)
    // so it decreases by 2r
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}