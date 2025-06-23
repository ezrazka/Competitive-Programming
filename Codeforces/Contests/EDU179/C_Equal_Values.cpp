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

    vector<int> leftmost(n);
    leftmost[0] = 0;
    for (int i = 1; i < n; i++){
        if (v[i - 1] == v[i]){
            leftmost[i] = leftmost[i - 1];
        } else {
            leftmost[i] = i;
        }
    }

    vector<int> rightmost(n);
    rightmost[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--){
        if (v[i] == v[i + 1]){
            rightmost[i] = rightmost[i + 1];
        } else {
            rightmost[i] = i;
        }
    }

    int ans = 1e18;
    for (int i = 0; i < n; i++){
        ans = min(ans, v[i] * ((leftmost[i]) + (n - 1 - rightmost[i])));
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