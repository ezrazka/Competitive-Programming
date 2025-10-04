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

    int sum = 0;
    for (int i = 0; i < n; i++){
        if (i & 1) sum -= v[i];
        else sum += v[i];
    }

    int bonus = (n - 1) / 2 * 2;
    {
        int mn = 1e18;
        for (int i = 0; i < n; i++){
            if (i & 1){
                int mx = 2 * v[i] + i;
                bonus = max(bonus, mx - mn);
            } else {
                mn = min(mn, 2 * v[i] + i);
            }
        }
    }
    {
        int mn = 1e18;
        for (int i = n - 1; i >= 0; i--){
            if (i & 1){
                int mx = 2 * v[i] - i;
                bonus = max(bonus, mx - mn);
            } else {
                mn = min(mn, 2 * v[i] - i);
            }
        }
    }
    cout << sum + bonus << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}