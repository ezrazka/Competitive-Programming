#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n, h, k; cin >> n >> h >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }
    vector<int> pref_min(n + 1, INF);
    for (int i = 1; i <= n; i++){
        pref_min[i] = min(pref_min[i - 1], a[i - 1]);
    }
    vector<int> suff_max(n + 2, -INF);
    for (int i = n; i >= 1; i--){
        suff_max[i] = max(suff_max[i + 1], a[i - 1]);
    }

    int l = 1, r = 2e18, res;
    while (l <= r){
        int mid = l + (r - l + 1) / 2;
        
        if (mid / (n + k) > 4e18 / pref[n]){
            r = mid - 1;
            continue;
        }

        
        int temp = mid;
        int dmg = 0;
        if (temp >= n){
            dmg += pref[n];
            temp -= n;
            dmg += (temp / (n + k)) * pref[n];
            temp %= n + k;
            temp = max(0ll, temp - k);
            if (temp){
                dmg += max(pref[temp], pref[temp] - pref_min[temp] + suff_max[temp + 1]);
            }
        } else {
            dmg += max(pref[temp], pref[temp] - pref_min[temp] + suff_max[temp + 1]);
        }

        if (dmg < h){
            l = mid + 1;
        } else {
            r = mid - 1;
            res = mid;
        }
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}