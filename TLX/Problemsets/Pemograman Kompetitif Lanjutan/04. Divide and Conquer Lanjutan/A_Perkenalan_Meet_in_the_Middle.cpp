#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, l, r; cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> left;
    auto rec1 = [&](auto self, int i, int sum) -> void {
        if (i == n / 2){
            left.push_back(sum);
            return;
        }
        
        self(self, i + 1, sum);
        self(self, i + 1, sum + v[i]);
    };
    rec1(rec1, 0, 0);
    sort(left.begin(), left.end());
    
    vector<int> right;
    auto rec2 = [&](auto self, int i, int sum) -> void {
        if (i == n){
            right.push_back(sum);
            return;
        }

        self(self, i + 1, sum);
        self(self, i + 1, sum + v[i]);
    };
    rec2(rec2, n / 2, 0);
    sort(right.begin(), right.end());

    int ans = 0;
    for (int i = 0; i < left.size(); i++){
        int ub = upper_bound(right.begin(), right.end(), r - left[i]) - right.begin();
        int lb = lower_bound(right.begin(), right.end(), l - left[i]) - right.begin();
        ans += ub - lb;
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