#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int N = 3e5;
vector<int> a(N);

struct cmp {
    bool operator()(int i, int j) const {
        return make_pair(a[i], i) < make_pair(a[j], j);
    }
};

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<bool> vis(n);
    set<int, cmp> st;
    for (int i = 0; i < n; i++){
        st.insert(i);
    }
    
    int ans = 0;
    while (!st.empty()){
        int i = *st.begin(); st.erase(i);
        vis[i] = true;
        if (i - 1 >= 0 && !vis[i - 1]){
            {
                vis[i - 1] = true;
                st.erase(i - 1);
                ans += a[i - 1];
                a[i - 1] = min(a[i - 1], a[i] + 1);
                ans -= a[i - 1];
                st.insert(i - 1);
            }
        }
        if (i + 1 < n && !vis[i + 1]){
            {
                vis[i + 1] = true;
                st.erase(i + 1);
                ans += a[i + 1];
                a[i + 1] = min(a[i + 1], a[i] + 1);
                ans -= a[i + 1];
                st.insert(i + 1);
            }
        }
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