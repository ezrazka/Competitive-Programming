#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = '0' + s;

    vector<int> next(n + 1);
    next[n] = -1;
    for (int i = n - 1; i >= 1; i--){
        if (s[i + 1] == '(') next[i] = i + 1;
        else next[i] = next[i + 1];
    }
    
    vector<int> suff(n + 2);
    for (int i = n; i >= 1; i--){
        suff[i] = suff[i + 1] + (s[i] == '(');
    }

    int ans = -1;
    for (int i = 1; i <= n; i++){
        if (next[i] == -1) continue;
        int need = next[i] - i - 1;
        if (need == 0) continue;
        if (suff[next[i]] > need){
            ans = max(ans, n - 2 * need);
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