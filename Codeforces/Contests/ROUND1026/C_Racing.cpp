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
    vector<int> d(n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }

    vector<int> dp_low(n + 1), dp_high(n + 1);
    for (int i = 1; i <= n; i++){
        dp_low[i] = dp_low[i - 1] + (d[i - 1] == 1);
        dp_high[i] = dp_high[i - 1] + (d[i - 1] != 0);
        if (dp_low[i] > r[i - 1] || dp_high[i] < l[i - 1]){
            cout << -1 << '\n';
            return;
        }
        dp_low[i] = max(dp_low[i], l[i - 1]);
        dp_high[i] = min(dp_high[i], r[i - 1]);
    }

    for (int i = n - 1; i >= 0; i--){
        dp_high[i] = min(dp_high[i], dp_high[i + 1] - (d[i] == 1));
    }

    for (int i = 0; i < n; i++){
        cout << dp_high[i + 1] - dp_high[i] << " \n"[i == n - 1];
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