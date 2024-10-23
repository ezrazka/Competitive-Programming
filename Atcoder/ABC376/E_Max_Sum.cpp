#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return a[i] < a[j];
        });

        int ans = 1e18;
        multiset<int> st;
        int sum = 0;
        int mx = 0;
        int i = 0;
        while (i < n){
            mx = max(mx, a[ord[i]]);
            while (i < n && a[ord[i]] == mx){
                st.insert(b[ord[i]]);
                sum += b[ord[i]];
                if (st.size() > k){
                    sum -= *--st.end();
                    st.erase(--st.end());
                }
                i++;
            }
            if (st.size() == k){
                ans = min(ans, mx * sum);
            }
        }
        cout << ans << '\n';
    }
}