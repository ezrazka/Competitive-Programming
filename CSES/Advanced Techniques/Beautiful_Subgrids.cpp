#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int N = 3000;

void solve(){
    int n; cin >> n;
    vector<bitset<N>> bits(N);
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < n; j++){
            if (s[j] - '0'){
                bits[i][j].flip();
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int cnt = (bits[i] & bits[j]).count();
            ans += cnt * (cnt - 1) / 2;
        }
    }
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