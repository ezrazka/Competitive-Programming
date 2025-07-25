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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    rotate(v.begin(), find(v.begin(), v.end(), 0) + 1, v.end());

    int ans = 0, cur = 0;
    stack<pair<int, int>> st;
    cur += n * 1;
    st.push({n, 1});
    ans = max(ans, cur);
    for (int i = 0; i < n - 1; i++){
        int cnt = 0;
        while (!st.empty() && st.top().fi >= v[i]){
            cnt += st.top().se;
            cur -= st.top().fi * st.top().se;
            st.pop();
        }
        cur += v[i] * cnt;
        st.push({v[i], cnt});
        cur += n * 1;
        st.push({n, 1});
        ans = max(ans, cur);
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