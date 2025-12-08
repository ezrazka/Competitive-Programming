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
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    int ans = 0, cnt = 0, odd = 0;
    for (auto [key, val] : mp){
        ans += (val - 1) % 2 + 1;
        cnt += (val % 4 == 0);
        odd += (val % 2 == 1);
    }
    cout << ans - 2 * (cnt % 2 == 1 && odd < 2) << '\n';
    /*
    1 2 3 4 5 4 1 4 1 5 4 6
    1 1 1 2 4 4 4 4 4 5 5 6
    odd, odd, even, odd, even, odd
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}