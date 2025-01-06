#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, d; cin >> n >> d;
    cout << 1 << ' ';
    if (n >= 3 || d % 3 == 0) cout << 3 << ' ';
    if (d == 5) cout << 5 << ' ';
    if (n >= 3 || d == 7) cout << 7 << ' ';
    if (n >= 6 || d % 9 == 0 || n >= 3 && d % 3 == 0) cout << 9 << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}