#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> right(n + 1);
    right[n] = n;
    for (int i = n - 1; i >= 0; i--){
        if (v[i] == 1){
            right[i] = right[i + 1];
        } else {
            right[i] = i;
        }
    }

    int last = -1;
    for (int i = n - 1; i >= 0; i--){
        if (v[i] != 1){
            last = i;
            break;
        }
    }

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + v[i];
    }

    int best = 0;
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < n; i++){
        if (v[i] == 1) continue;
        int cur = i;
        int product = 1;
        while (cur < n){
            product *= v[cur];
            int cur_best = pref[n] - (pref[cur + 1] - pref[i]) + product;
            if (cur_best > best){
                best = cur_best;
                ans = {i, cur};
            }
            if (product > 2 * n){
                cout << i + 1 << ' ' << last + 1 << '\n';
                return;
            }
            cur = right[cur + 1];
        }
    }
    cout << ans.fi + 1 << ' ' << ans.se + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}