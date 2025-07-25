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

    int ans = 0;
    bool square_bottom = false;
    bool square_top = false;
    for (int i = 0; i < n; i++){
        if (v[i] == 0){
            square_bottom = false;
            square_top = false;
        } else if (square_bottom && v[i] <= 2){
            square_bottom = false;
        } else if (v[i] <= 2){
            square_top = false;
            square_bottom = true;
            ans++;
        } else if (square_bottom && v[i] <= 4){
            square_bottom = false;
            square_top = true;
            ans++;
        } else if (square_top && v[i] <= 4){
            square_top = false;
            square_bottom = true;
            ans++;
        } else {
            square_bottom = false;
            square_top = false;
            ans++;
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