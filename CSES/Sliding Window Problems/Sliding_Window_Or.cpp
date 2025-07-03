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

    stack<pair<int, int>> in, out;
    for (int i = 0; i < k; i++){
        in.push({v[i], in.empty() ? v[i] : v[i] | in.top().se});
    }

    int ans = in.top().se;
    for (int i = k; i < n; i++){
        in.push({v[i], in.empty() ? v[i] : v[i] | in.top().se});
        if (out.empty()){
            while (!in.empty()){
                out.push({in.top().fi, out.empty() ? in.top().fi : in.top().fi | out.top().se});
                in.pop();
            }
        }
        out.pop();
        ans ^= (in.empty() ? 0 : in.top().se) | (out.empty() ? 0 : out.top().se);
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