#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, h; cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    auto calc = [&](int l, int r, int h) -> pair<int, int> {
        pair<int, int> res = {-1, -1};
        for (int idx = l; idx <= r; idx++){
            int sum = a[idx] - h;
            {
                int i = idx, j = idx;
                while (j <= r){
                    while (j <= r && a[i] >= a[j]) j++;
                    sum += (j - i) * (h - a[i]);
                    i = j;
                }
            }
            {
                int i = idx, j = idx;
                while (j >= l){
                    while (j >= l && a[i] >= a[j]) j--;
                    sum += (i - j) * (h - a[i]);
                    i = j;
                }
            }
            if (sum > res.second){
                res = {idx, sum};
            }
        }
        return res;
    };

    auto [idx, val1] = calc(0, n - 1, h);
    int ans = val1;
    {

        int i = idx, j = idx;
        while (j < n){
            while (j < n && a[i] >= a[j]) j++;
            auto [_, val2] = calc(i, j - 1, a[i]);
            ans = max(ans, val1 + val2);
            i = j;
        }
    }
    {
        int i = idx, j = idx;
        while (j >= 0){
            while (j >= 0 && a[i] >= a[j]) j--;
            auto [_, val2] = calc(j + 1, i, a[i]);
            ans = max(ans, val1 + val2);
            i = j;
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