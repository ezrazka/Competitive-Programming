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
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    ld l = 0, r = 2e9, ans;
    while (r - l > EPS){
        ld mid = (l + r) / 2;

        int m_need = 0;
        for (int i = 0; i < n; i++){
            m_need += ceil(v[i] / mid);
        }

        if (m < m_need){
            l = mid;
        } else {
            r = mid;
            ans = mid;
        }
    }
    cout << fixed << setprecision(2) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}