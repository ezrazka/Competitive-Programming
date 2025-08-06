#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int l = 1, r = n;
    array<int, 3> ans = {-1, -1, -1};
    while (l <= r){
        int mid = (l + r) / 2;

        vector<int> signs(n + 1);
        for (int i = 1; i <= n; i++) signs[i] = signs[i - 1] + (v[i - 1] >= mid ? 1 : -1);
        vector<int> pref = signs, suff = signs;
        for (int i = 1; i <= n; i++) pref[i] = min(pref[i], pref[i - 1]);
        for (int i = n - 1; i >= 0; i--) suff[i] = max(suff[i], suff[i + 1]);

        bool ok = false;
        int ans1 = -1, ans2 = -1;
        for (int i = k; i <= n; i++){
            if (suff[i] - pref[i - k] >= 0){
                ok = true;
                for (int j = 0; j <= i - k; j++){
                    if (signs[j] == pref[i - k]){
                        ans1 = j;
                        break;
                    }
                }
                for (int j = n; j >= i; j--){
                    if (signs[j] == suff[i]){
                        ans2 = j - 1;
                        break;
                    }
                }
                break;
            }
        }

        if (ok){
            l = mid + 1;
            ans = {mid, ans1, ans2};
        } else {
            r = mid - 1;
        }
    }
    cout << ans[0] << ' ' << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}