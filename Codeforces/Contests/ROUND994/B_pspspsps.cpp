#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (s[i] == 'p' && s[j] == 's'){
                if (i - j + 1 < min(i - 0 + 1, n - 1 - j + 1)){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}