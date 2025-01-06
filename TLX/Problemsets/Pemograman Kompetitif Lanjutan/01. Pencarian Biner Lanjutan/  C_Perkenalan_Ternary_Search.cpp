#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const ld EPS = 1e-4;

void solve(){
    int n; cin >> n;
    vector<ld> v(n);
    ld mn = 1e9, mx = -1e9;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mn = min(mn, v[i]);
        mx = min(mx, v[i]);
    }

    ld l = -1000, r = 1000;
    while (r - l > EPS){
        ld mid1 = l + (r - l) / 3;
        ld mid2 = r - (r - l) / 3;

        ld f1 = 0, f2 = 0;
        for (int i = 0; i < n; i++){
            f1 += sqrt(abs(v[i] - mid1) * abs(v[i] - mid1) * abs(v[i] - mid1));
            f2 += sqrt(abs(v[i] - mid2) * abs(v[i] - mid2) * abs(v[i] - mid2));
        }

        if (f1 > f2){
            l = mid1;
        } else {
            r = mid2;
        }
    }
    cout << fixed << setprecision(2) << l << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}