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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    int left = n + 1;
    for (int i = 1; i <= n; i++){
        if (v[i] != 0 && v[i] != i){
            left = i;
            break;
        }
    }
    int right = 0;
    for (int i = n; i >= 1; i--){
        if (v[i] != 0 && v[i] != i){
            right = i;
            break;
        }
    }
    if (count(v.begin() + 1, v.end(), 0) > 1){
        for (int i = 1; i <= n; i++){
            if (v[i] == 0){
                left = min(left, i);
                break;
            }
        }
        for (int i = n; i >= 1; i--){
            if (v[i] == 0){
                right = max(right, i);
                break;
            }
        }
    }
    vector<bool> found(n + 1);
    for (int i = 1; i <= n; i++){
        found[v[i]] = true;
    }
    for (int i = 1; i <= n; i++){
        if (found[i] && v[i] == 0){
            left = min(left, i);
            right = max(right, i);
        }
    }
    cout << max(0ll, right - left + 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}