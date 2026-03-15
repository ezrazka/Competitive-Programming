#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    auto calc = [&](int x){
        return (x == 0 ? 1 : 1 << __lg(2 * x - 1)) - x;
    };

    int ans = INF;
    vector<bool> valid(n + 1);
    vector<int> pref = {0};
    for (int i = 1, j = 1; i <= n;){
        while (j <= n && a[i] == a[j]) j++;
        pref.push_back(pref.back() + (j - i));
        valid[pref.back()] = true;
        i = j;
    }
    vector<int> xs;
    for (int i = 1; i <= n; i++){
        if (__builtin_popcount(i) == 1){
            int x = *prev(upper_bound(pref.begin(), pref.end(), i));
            xs.push_back(x);
        }
        if (!valid[i]) continue;
        for (int x : xs){
            int y = i - x;
            int z = n - i;
            ans = min(ans, calc(x) + calc(y) + calc(z));
        }
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