#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    vector<int> a(6);
    for (int i = 0; i < 6; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    int ans = INF;
    multiset<pair<int, pair<int, int>>> ms;
    for (int i = 0; i < n; i++){
        ms.emplace(b[i] - a[0], pair<int, int>{i, 0});
    }
    while (true){
        ans = min(ans, ms.rbegin()->first - ms.begin()->first);
        auto [i, j] = ms.begin()->second;
        if (j + 1 == 6) break;
        ms.erase(ms.begin());
        ms.emplace(b[i] - a[j + 1], pair<int, int>{i, j + 1});
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}