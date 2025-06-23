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

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return v[i] < v[j];
    });

    vector<int> left(n, -1), right(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && v[i] > v[st.top()]){
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++){
        while (!st.empty() && v[i] > v[st.top()]){
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++){
        if (left[ord[i]] != -1) dp[left[ord[i]]] = max(dp[left[ord[i]]], dp[ord[i]] + 1);
        if (right[ord[i]] != -1) dp[right[ord[i]]] = max(dp[right[ord[i]]], dp[ord[i]] + 1);
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