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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, int> freq;
    set<pair<int, int>> st;
    for (int i = 0; i < k; i++){
        auto it = st.find({freq[v[i]], -v[i]});
        if (it != st.end()) st.erase(it);
        freq[v[i]]++;
        st.insert({freq[v[i]], -v[i]});
    }
    
    cout << -(*st.rbegin()).se << ' ';
    for (int i = k; i < n; i++){
        {
            auto it = st.find({freq[v[i]], -v[i]});
            if (it != st.end()) st.erase(it);
            freq[v[i]]++;
            st.insert({freq[v[i]], -v[i]});
        }
        {
            auto it = st.find({freq[v[i - k]], -v[i - k]});
            if (it != st.end()) st.erase(it);
            freq[v[i - k]]--;
            st.insert({freq[v[i - k]], -v[i - k]});
        }
        cout << -(*st.rbegin()).se << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}