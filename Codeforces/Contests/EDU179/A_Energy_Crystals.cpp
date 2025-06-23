#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int x; cin >> x;

    vector<int> a(3);
    int cnt = 2;
    while (a[2] < x){
        cnt++;
        a[0] = a[1] * 2 + 1;
        sort(a.begin(), a.end());
    }
    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}