#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt_0 = count(s.begin(), s.end(), '0');
    int cnt_1 = count(s.begin(), s.end(), '1');

    int mn = max(cnt_0, cnt_1) - n / 2;
    int mx = cnt_0 / 2 + cnt_1 / 2;
    cout << ((k & 1) == (mn & 1) && mn <= k && k <= mx ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}