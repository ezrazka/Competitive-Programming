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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }

    int ans = 0;
    {
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
            return a.fi < b.fi;
        });
        int sum = 0;
        for (int i = 1; i < n; i++){
            sum += v[i].fi - v[0].fi;
            ans += sum;
        }
    }
    {
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
            return a.se < b.se;
        });
        int sum = 0;
        for (int i = 1; i < n; i++){
            sum += v[i].se - v[0].se;
            ans += sum;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t
    while (t--)
        solve();
    return 0;
}