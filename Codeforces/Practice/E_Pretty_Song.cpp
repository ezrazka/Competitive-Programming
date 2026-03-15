#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        bool found = false;
        for (char c : {'A', 'E', 'I', 'O', 'U', 'Y'}){
            if (s[i - 1] == c){
                found = true;
                break;
            }
        }
        pref[i] = pref[i - 1] + found;
    }

    vector<int> denom(n + 2);
    for (int i = 1; i <= (n + 1) / 2; i++){
        denom[i] += pref[n - i + 1] - pref[i - 1];
        denom[n - i + 2] -= pref[n - i + 1] - pref[i - 1];
    }

    for (int i = 2; i <= n; i++){
        denom[i] += denom[i - 1];
    }

    ld ans = 0;
    for (int i = 1; i <= n; i++){
        ans += (ld) denom[i] / i;
    }
    cout << fixed << setprecision(7) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}