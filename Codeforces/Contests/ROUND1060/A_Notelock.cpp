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

    int ans = 0;
    for (int i = 0; i < n; i++){
        bool ok = true;
        for (int j = i - 1; j > i - k; j--){
            if (s[j] == '1'){
                ok = false;
            }
        }
        if (s[i] == '1' && ok) ans++;
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