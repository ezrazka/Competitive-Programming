#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int S(int n){
    return n * (n + 1) / 2;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + v[i - 1];
    }

    vector<int> pref2(n + 1);
    for (int i = 1; i <= n; i++){
        pref2[i] = pref2[i - 1] + pref[i];
    }

    vector<int> pref3(n + 1);
    for (int i = 1; i <= n; i++){
        pref3[i] = pref3[i - 1] + (pref2[n] - pref2[i - 1] - (n + 1 - i) * pref[i - 1]);
    }

    auto calc = [&](int a) -> int {
        int l = 0, r = n, res = 0;
        while (l <= r){
            int mid = (l + r) / 2;

            if (S(n) - S(n - mid) <= a){
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        int remainder = (a) - (S(n) - S(n - res));
        int total_left = pref3[res] + (pref2[res + remainder] - pref2[res] - remainder * pref[res]);
        return total_left;
    };

    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;

        cout << calc(b) - calc(a - 1) << '\n';
        // 1 3 8 18 - 2 7 17 - 5 15 - 10
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}