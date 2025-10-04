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

    int ans = 0;
    for (int i = 1; i < n; i += 2){
        int sum = max(0ll, v[i - 1] + (i + 1 < n ? v[i + 1] : 0) - v[i]);
        int left, right;
        if (i == n - 1) left = sum;
        else right = min(v[i + 1], sum), left = sum - right;
        if (i == n - 1){
            v[i - 1] -= left;
        } else {
            v[i + 1] -= right;
            v[i - 1] -= left;
        }
        ans += sum;
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}