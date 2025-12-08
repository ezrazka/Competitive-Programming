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
    string s; cin >> s;
    
    int ans = 1e18;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
    }
    vector<int> suff(n + 2);
    map<int, int> sums;
    sums[0] = 0;
    for (int i = n; i >= 0; i--){
        // pref + suff = 0
        // suff = -pref
        if (sums.find(-pref[i]) != sums.end()){
            if (!(i == 0 && sums[-pref[0]] == 0)){
                ans = min(ans, n - (i + sums[-pref[i]]));
            }
        }
        suff[i] = suff[i + 1] + (s[i - 1] == 'a' ? 1 : -1);
        sums[suff[i]] = n + 1 - i;
    }
    cout << (ans == (int) 1e18 ? -1 : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}