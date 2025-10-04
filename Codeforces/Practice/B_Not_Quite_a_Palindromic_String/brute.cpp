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

    sort(s.begin(), s.end());
    do {
        int cnt = 0;
        for (int i = 0; i < n / 2; i++){
            if (s[i] == s[(n - 1) - i]){
                cnt++;
            }
        }
        if (cnt == k){
            cout << "YES\n";
            return;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}