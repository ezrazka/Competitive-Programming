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
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> vans;
    set<int> st(a.begin(), a.end());
    set<int> vis;
    while (!st.empty()){
        int x = *st.begin();
        if (vis.find(x) == vis.end()){
            for (int i = x; i <= k; i += x){
                if (st.find(i) == st.end()){
                    cout << -1 << '\n';
                    return;
                } else {
                    vis.insert(i);
                }
            }
            vans.push_back(x);
        }
        st.erase(x);
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}