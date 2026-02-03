#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x = a[1];
    a.erase(a.begin());
    n--;

    vector<int> pref_abs_sum(n + 1), suff_sum(n + 2);
    for (int i = 1; i <= n; i++) pref_abs_sum[i] = pref_abs_sum[i - 1] + abs(a[i]);
    for (int i = n; i >= 1; i--) suff_sum[i] = suff_sum[i + 1] + a[i];

    int ans = -suff_sum[1];
    for (int i = 1; i <= n; i++){
        ans = max(ans, pref_abs_sum[i - 1] - suff_sum[i + 1] + x);
    }
    cout << ans << '\n';

    /*
    a[1] can only be positive
    a[n] can only be negative
    a[2..n-1] can be negative
    a[2..n-1] can be positive if the omitted index is to the right of it

    pref_abs[i] + suff[i];
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