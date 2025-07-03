#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++){
        v[i] = (a * v[i - 1] + b) % c;
    }

    deque<int> dq;
    for (int i = 0; i < k; i++){
        while (!dq.empty() && v[i] < v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    int ans = v[dq.front()];
    for (int i = k; i < n; i++){
        if (dq.front() == i - k) dq.pop_front();
        while (!dq.empty() && v[i] < v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans ^= v[dq.front()];
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