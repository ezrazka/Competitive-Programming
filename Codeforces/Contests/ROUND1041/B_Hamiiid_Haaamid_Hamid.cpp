#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k; k--;
    string s; cin >> s;

    int left = -1, right = n;
    for (int i = k - 1; i >= 0; i--){
        if (s[i] == '#'){
            left = i;
            break;
        }
    }
    for (int i = k + 1; i < n; i++){
        if (s[i] == '#'){
            right = i;
            break;
        }
    }
    cout << max(min(k + 1, n - right + 1), min(n - k, left + 2)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}