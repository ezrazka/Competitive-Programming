#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n;i ++){
        pref[i] = pref[i - 1] + v[i - 1];
    }

    int ans = -1e18;
    deque<int> dq;
    for (int i = 0; i < n; i++){
        if (!dq.empty() && dq.front() == i - b){
            dq.pop_front();
        }
        if (i - a + 1 >= 0){
            while (!dq.empty() && pref[dq.back()] > pref[i - a + 1]){
                dq.pop_back();
            }
            dq.push_back(i - a + 1);
        }
        if (!dq.empty()){
            ans = max(ans, pref[i + 1] - pref[dq.front()]);
        }
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