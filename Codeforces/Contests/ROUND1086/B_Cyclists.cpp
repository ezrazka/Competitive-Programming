#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k, p, m; cin >> n >> k >> p >> m; p--;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    int ans = 0;
    while (true){
        int cheapest = -1;
        int win_condition = -1;
        {
            for (int i = 0; i < k; i++){
                if (cheapest == -1 || a[i].first < a[cheapest].first) cheapest = i;
                if (a[i].second == p) win_condition = i;
            }
        }
        int idx = (win_condition != -1 ? win_condition : cheapest);
        if (a[idx].first > m) break;
        m -= a[idx].first;
        a.push_back(a[idx]);
        a.erase(a.begin() + idx);
        if (idx == win_condition) ans++;
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