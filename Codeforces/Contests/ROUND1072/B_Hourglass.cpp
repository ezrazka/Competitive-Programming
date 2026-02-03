#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int s, k, m; cin >> s >> k >> m;
    
    if ((m / k) & 1) cout << max(0ll, min(s, k) - m % k) << '\n';
    else cout << max(0ll, s - m % k) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}