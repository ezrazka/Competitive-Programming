#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int l = 1, r = n, res;
    while (l <= r){
        int mid = (l + r) / 2;

        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++){
            pref[i] = pref[i - 1] + (a[i] >= mid ? 1 : -1);
        }

        bool ok = false;
        int mn = INF;
        for (int i = k; i <= n; i++){
            mn = min(mn, pref[i - k]);
            if (mn < pref[i]){
                ok = true;
                break;
            }
        }

        if (ok){
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}