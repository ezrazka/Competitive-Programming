#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 1; i <= n - 1; i++){
        sum += abs(a[i] - a[i + 1]);
    }

    int ans = sum;
    for (int i = 1; i <= n; i++){
        int cur = sum;
        if (i >= 2) cur -= abs(a[i - 1] - a[i]);
        if (i <= n - 1) cur -= abs(a[i] - a[i + 1]);
        if (2 <= i && i <= n - 1) cur += abs(a[i - 1] - a[i + 1]);
        ans = min(ans, cur);
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