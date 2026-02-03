#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, s, x; cin >> n >> s >> x;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

    cout << (s >= sum && (s - sum) % x == 0 ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}