#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    int ans = 0;
    vector<int> diff(n + k);
    int len = 0;
    for (int i = 0; i < n; i++){
        if (i > 0) diff[i] += diff[i - 1];
        if (s[i] == '0' && diff[i] == 0){
            len++;
        } else {
            len = 0;
        }
        if (len == m){
            diff[i]++;
            diff[i + k]--;
            len = 0;
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