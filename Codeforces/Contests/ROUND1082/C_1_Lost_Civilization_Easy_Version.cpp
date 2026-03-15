#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = n;
    int mn = a[0], mx = a[0];
    for (int i = 1; i < n; i++){
        if (mn < a[i] && a[i] <= mx + 1 && a[i] - a[i - 1] < 2){
            mx = max(mx, a[i]);
            ans--;
        } else {
            mn = a[i], mx = a[i];
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