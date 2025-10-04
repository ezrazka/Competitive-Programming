#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;
    stack<int> st;
    for (int i = 0; i < n; i++){
        while (!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        }
        if (st.empty()) ans += i + 1;
        else ans += i - st.top();
        st.push(i);
    }
    cout << ans << '\n';
}