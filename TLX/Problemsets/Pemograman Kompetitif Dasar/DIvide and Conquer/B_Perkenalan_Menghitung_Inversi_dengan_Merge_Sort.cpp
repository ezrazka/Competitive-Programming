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

    int ans = 0;
    auto merge_sort = [&](auto self, int l, int r) -> vector<int> {
        if (l == r){
            return {v[l]};
        }

        int mid = (l + r) / 2;
        vector<int> vl = self(self, l, mid);
        vector<int> vr = self(self, mid + 1, r);

        vector<int> vlr;
        int i = 0, j = 0;
        int rights = 0;
        while (i < vl.size() || j < vr.size()){
            if (i < vl.size() && (j == vr.size() || vl[i] <= vr[j])){
                vlr.push_back(vl[i++]);
                ans += rights;
            } else {
                vlr.push_back(vr[j++]);
                rights++;
            }
        }

        return vlr;
    };
    merge_sort(merge_sort, 0, n - 1);
    
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