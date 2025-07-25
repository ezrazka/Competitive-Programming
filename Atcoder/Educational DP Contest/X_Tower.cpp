#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct element {
    int w, s, v;
};

void solve(){
    int n; cin >> n;
    vector<element> v(n);
    int w_mx = 0, s_mx = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].w >> v[i].s >> v[i].v;
        w_mx = max(w_mx, v[i].w);
        s_mx = max(s_mx, v[i].s);
    }
    sort(v.begin(), v.end(), [&](element a, element b){
        return a.w + a.s < b.w + b.s;
    });

    vector<int> dp(w_mx + s_mx + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = v[i].s; j >= 0; j--){
            if (j + v[i].w <= w_mx + s_mx && dp[j] != -1){
                dp[j + v[i].w] = max(dp[j + v[i].w], dp[j] + v[i].v);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}