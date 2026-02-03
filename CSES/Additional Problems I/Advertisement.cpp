#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> left(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++){
        while (!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if (!st.empty()){
            left[i] = st.top();
        }
        st.push(i);
    }
    vector<int> right(n, n);
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if (!st.empty()){
            right[i] = st.top();
        }
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, v[i] * (right[i] - left[i] - 1));
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