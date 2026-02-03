#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        int cur = i - (upper_bound(b.begin(), b.end(), a[i]) - b.begin() - 1);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    /*
    4 3 2 5 1 4 2
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}