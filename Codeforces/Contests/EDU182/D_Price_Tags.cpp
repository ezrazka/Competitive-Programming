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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int mx = *max_element(v.begin() + 1, v.end());

    if (mx == 1){
        cout << n << '\n';
        return;
    }

    vector<int> freq(mx + 1);
    for (int i = 1; i <= n; i++){
        freq[v[i]]++;
    }
    vector<int> pref(mx + 1);
    for (int i = 1; i <= mx; i++){
        pref[i] = pref[i - 1] + freq[i];
    }

    int ans = -1e18;
    for (int x = 2; x <= mx; x++){
        int sum = 0, need = 0;
        for (int i = 1; i <= (mx + x - 1) / x; i++){
            int cnt = pref[min(mx, i * x)] - pref[(i - 1) * x];
            sum += cnt * i;
            need += max(0ll, cnt - freq[i]);
        }
        ans = max(ans, sum - k * need);
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