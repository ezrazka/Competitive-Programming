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

    vector<bool> red(n);
    int ans = 0;
    int segment = 0;
    for (int i = 0; i < n; i++){
        if (v[i]){
            if (segment == 0){
                if (i == 0 || red[i - 1]){
                    segment = 2;
                } else {
                    red[i - 1] = true;
                }
                ans++;
            }
            red[i] = true;
            segment = max(segment, v[i]);
        } else {
            if (segment == 2){
                red[i] = true;
            }
            segment = 0;
        }
    }
    ans += count(red.begin(), red.end(), false);

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